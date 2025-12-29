#include "utility.h"

std::string Utility::codify(const std::string& str)
{
    std::string res;
    bool flag{true};
    char c;
    for (auto it = str.begin(); it != str.end(); it++) {
        c = *it;
        if (isblank(c)) {
            if (flag)
                continue;
            flag = true;
            c = '_';
        }
        else {
            if (isupper(c))
                c = tolower(c);
            flag = false;
        }

        res.push_back(c);
    }

    return res;
}

std::string Utility::keyfy(const std::string& str)
{
    std::string res;
    char c;
    for (auto it = str.begin(); it != str.end(); it++) {
        c = *it;
        if (isalpha(c))
            res.push_back(tolower(c));
    }
    
    return res;
}

std::string Utility::displayfy(const std::string& str)
{
    std::string res;
    char c;
    bool flag{false};
    for (auto it = str.begin(); it != str.end(); it++){
        c = *it;
        if (c == '_') {
            c = ' ';
            flag = true;
        }
        else if (it == str.begin() || flag) {
            c = toupper(c);
            flag = false;
        }
        res.push_back(c);
    }

    return res;
}

std::string Utility::lowerize(const std::string& str)
{
    std::string res;
    char c;
    for (auto it = str.begin(); it != str.end(); it++){
        c = *it;
        res.push_back(tolower(c));
    }

    return res;
}
