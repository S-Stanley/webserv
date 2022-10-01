#include "helpers.hpp"

std::string remove_space(std::string str)
{
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    return (str);
}