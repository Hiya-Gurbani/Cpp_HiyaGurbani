#ifndef UTILS_H
#define UTILS_H

class Utils {
public:

    static std::string& moveTypeToString(Constants::MoveType moveType);
    static std::string& movePermissionToString(Constants::MovePermission movePermission);
    static std::string& Utils::directionToString(Constants::Direction direction);
    static bool stringToDirection(const std::string& input, Constants::Direction& outDirection);
};

#endif
