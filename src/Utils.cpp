#include "Utils.h"

std::string& Utils::moveTypeToString(Constants::MoveType moveType) {
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

std::string& Utils::movePermissionToString(Constants::MovePermission movePermission) {
    std::string result;

    switch (movePermission) 
    {
        case MovePermission::FREE:
        {
            result = "Always Allowed";
            break;
        }
        case MovePermission::NEEDS_GREEN: 
        {
            result = "Needs Green Light";
            break;
        }
        default:                          
        {
            result = "UNKNOWN";
        }
    }

    return result;
}

std::string& Utils::directionToString(Constants::Direction direction) {
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
