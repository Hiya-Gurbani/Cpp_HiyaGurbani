#include "Utils.h"
#include "Constants.h"

std::string Utils::moveTypeToString(Constants::MoveType moveType) {
    std::string result;

    switch (moveType)
    {
        case Constants::MoveType::UTURN:    
        { 
            result = "U-Turn";     
            break; 
        }
        case Constants::MoveType::LEFT:     
        { 
            result = "Left Turn";  
            break; 
        }
        case Constants::MoveType::RIGHT:    
        { 
            result = "Right Turn"; 
            break; 
        }
        case Constants::MoveType::STRAIGHT: 
        { 
            result = "Straight";   
            break; 
        }
    }

    return result;
}

std::string Utils::directionToString(Constants::Direction direction) {
    std::string result;

    switch (direction)
    {
        case Constants::Direction::NORTH:
        { 
            result = "NORTH"; 
            break; 
        }
        case Constants::Direction::SOUTH: 
        { 
            result = "SOUTH"; 
            break; 
        }
        case Constants::Direction::EAST:  
        { 
            result = "EAST";  
            break; 
        }
        case Constants::Direction::WEST:  
        { 
            result = "WEST";  
            break; 
        }
    }

    return result;
}

bool Utils::stringToDirection(const std::string& input, Constants::Direction& outDirection) {
    bool isValid = true;

    if (input == "N" || input == "NORTH")       
    { 
        outDirection = Constants::Direction::NORTH; 
    }
    else if (input == "S" || input == "SOUTH")  
    { 
        outDirection = Constants::Direction::SOUTH; 
    }
    else if (input == "E" || input == "EAST")   
    { 
        outDirection = Constants::Direction::EAST;  
    }
    else if (input == "W" || input == "WEST")   
    { 
        outDirection = Constants::Direction::WEST;  
    }
    else                                        
    { 
        isValid = false; 
    }

    return isValid;
}

Constants::MoveType Utils::determineMoveType(Constants::Direction fromLane, Constants::Direction toLane) {
    using Move = Constants::MoveType;

    static const Move moveTable[4][4] = {
        { Move::UTURN,    Move::LEFT,      Move::STRAIGHT,  Move::RIGHT    },
        { Move::LEFT,     Move::UTURN,     Move::RIGHT,     Move::STRAIGHT },
        { Move::STRAIGHT, Move::RIGHT,     Move::UTURN,     Move::LEFT     },
        { Move::RIGHT,    Move::STRAIGHT,  Move::LEFT,      Move::UTURN    } 
    };
    
    return moveTable[(int)fromLane][(int)toLane];
}
