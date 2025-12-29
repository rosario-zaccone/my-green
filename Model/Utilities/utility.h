#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <cctype>

class Utility
{
public:
    static std::string codify(const std::string& str); //  Common Wolf -> common_wolf
    static std::string keyfy(const std::string& str); // common_wolf -> commonwolf
    static std::string displayfy(const std::string& str); // common_wolf -> Common Wolf
    static std::string lowerize(const std::string& str);  // COMMON WOLF -> common wolf
};

#endif // UTILITY_H
