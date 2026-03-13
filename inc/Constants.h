#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
    enum class Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    enum class MoveType {
        UTURN,
        LEFT,
        RIGHT,
        STRAIGHT
    };

    // In future, any lane could be Blocked
    enum class MovePermission {
        FREE,           
        NEEDS_GREEN     
    };
    
    const int GREEN_DURATION_SECONDS = 10;

    inline const std::string MSG_WELCOME =
        "\n========================================\n"
        "       TRAFFIC LIGHT SIMULATION         \n"
        "========================================\n"
        "   Semaphore-based crossroad controller \n"
        "========================================\n";

    inline const std::string MSG_ROAD =
        "\n          |  N  |\n"
        "          |  ^  |\n"
        "          |     |\n"
        "----------+     +----------\n"
        "  W <                > E   \n"
        "----------+     +----------\n"
        "          |     |\n"
        "          |  v  |\n"
        "          |  S  |\n";

    inline const std::string MSG_ENTER_LANE = "\nWhich lane are you in? (N/S/E/W): ";

    inline const std::string MSG_ENTER_DESTINATION = "Where do you want to go?  (N/S/E/W): ";

    inline const std::string MSG_ASK_ANOTHER_QUERY = "\nAnother query? (y/n): ";

    inline const std::string MSG_GOODBYE = "\nThank you for using Traffic Light Simulation. Goodbye.\n";

    inline const std::string MSG_DIVIDER = "\n----------------------------------------\n";

    inline const std::string WHITESPACE_CHARS = " \t\r\n";
    inline const std::string EMPTY_STRING = "";
    inline const std::string MSG_EMPTY_INPUT = "Input cannot be empty. Please try again.\n";

    inline const std::string MSG_CAN_GO = "Status : GO — You can proceed now.\n";

    inline const std::string MSG_MUST_WAIT = "Status : WAIT — Your lane is red.\n";

    inline const std::string MSG_FREE_MOVE = "Note : This is a free move, no green light needed.\n";
}

#endif
