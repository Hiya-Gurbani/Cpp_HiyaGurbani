#include "UserController.h"
#include "Utils.h"

UserController::UserController(
    IInputHandler* inputHandler,
    ILogger* logger,
    TrafficState* trafficState,
    const std::vector<Lane>& orderedLaneCycle)
    : inputHandler(inputHandler)
    , logger(logger)
    , trafficState(trafficState)
    , orderedLaneCycle(orderedLaneCycle)
{}

Constants::Direction UserController::getLane(const std::string& prompt) {
    std::string laneInput;
    Constants::Direction currentLane = Constants::Direction::NORTH;

    while (true)
    {
        logger->printMessage(prompt);
        inputHandler->inputString(laneInput);

        if (!Utils::stringToDirection(laneInput, currentLane))
        {
            logger->printMessage(Constants::MSG_INVALID_INPUT);
        }
        else
        {
            break;
        }
    }

    return currentLane;
}

int UserController::calculateWaitTimeInSeconds(Constants::Direction fromLane, const TrafficState& snapshot) {
    int waitSeconds = 0;

    int activeIndex = 0;
    for (int index = 0; index < (int)orderedLaneCycle.size(); index++)
    {
        if (orderedLaneCycle[index].direction == snapshot.activeLane)
        {
            activeIndex = index;
            break;
        }
    }

    if (orderedLaneCycle[activeIndex].direction == fromLane)
    {
        waitSeconds = 0;
    }
    else
    {
        waitSeconds = snapshot.timeRemaining;
        int totalLanes = (int)orderedLaneCycle.size();
        int current = (activeIndex + 1) % totalLanes;

        while (orderedLaneCycle[current].direction != fromLane)
        {
            waitSeconds += orderedLaneCycle[current].greenLightDuration;
            current = (current + 1) % totalLanes;
        }
    }

    return waitSeconds;
}

void UserController::processQuery(Constants::Direction fromLane, Constants::Direction toLane) {
    TrafficState snapshot;
    {
        std::lock_guard<std::mutex> lock(trafficState->stateMutex);
        snapshot.activeLane    = trafficState->activeLane;
        snapshot.timeRemaining = trafficState->timeRemaining;
    }

    MoveResult result;
    result.fromLane = fromLane;
    result.toLane = toLane;
    result.currentGreenLane = snapshot.activeLane;
    result.timeRemaining = snapshot.timeRemaining;
    result.moveType = Utils::determineMoveType(fromLane, toLane);

    if (result.moveType == Constants::MoveType::UTURN || result.moveType == Constants::MoveType::LEFT)
    {
        result.permission = Constants::MovePermission::FREE;
        result.canGoNow = true;
        result.waitSeconds = 0;
    }
    else
    {
        result.permission = Constants::MovePermission::NEEDS_GREEN;
        result.waitSeconds = calculateWaitTimeInSeconds(fromLane, snapshot);
        result.canGoNow = (result.waitSeconds == 0);
    }

    displayMoveResult(result);
}

void UserController::displayMoveResult(const MoveResult& result)
{
    logger->printMessage(Constants::MSG_DIVIDER);
    logger->printMessage("From : " + Utils::directionToString(result.fromLane) + "\n");
    logger->printMessage("To   : " + Utils::directionToString(result.toLane) + "\n");
    logger->printMessage("Move : " + Utils::moveTypeToString(result.moveType) + "\n");
    logger->printNewLine();

    if (result.canGoNow)
    {
        logger->printMessage(Constants::MSG_CAN_GO);
        if (result.permission == Constants::MovePermission::FREE)
        {
            logger->printMessage(Constants::MSG_FREE_MOVE);
        }
    }
    else
    {
        logger->printMessage(Constants::MSG_MUST_WAIT);
        logger->printMessage("Current green : " + Utils::directionToString(result.currentGreenLane) + "\n");
        logger->printMessage("Time remaining: " + std::to_string(result.timeRemaining) + " seconds\n");
        logger->printMessage("Your wait     : " + std::to_string(result.waitSeconds) + " seconds\n");
    }

    logger->printMessage(Constants::MSG_DIVIDER);
}

bool UserController::askUserToContinue() {
    bool shouldContinue = false;

    while (true)
    {
        logger->printMessage(Constants::MSG_ASK_ANOTHER_QUERY);
        std::string continueInput;
        inputHandler->inputString(continueInput);

        if (continueInput == "y" || continueInput == "Y")
        {
            shouldContinue = true;
            break;
        }
        else if (continueInput == "n" || continueInput == "N")
        {
            shouldContinue = false;
            break;
        }
        else
        {
            logger->printMessage(Constants::MSG_INVALID_CONTINUE_INPUT);
        }
    }

    return shouldContinue;
}

void UserController::handleUserQueries()
{
    while (true)
    {
        Constants::Direction fromLane = getLane(Constants::MSG_ENTER_LANE);
        Constants::Direction toLane   = getLane(Constants::MSG_ENTER_DESTINATION);

        processQuery(fromLane, toLane);

        if (!askUserToContinue())
        {
            break;
        }
    }

    logger->printMessage(Constants::MSG_GOODBYE);
}
