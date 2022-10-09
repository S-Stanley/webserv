#include "helpers.hpp"

std::string split_string(std::string str, std::string delimiter)
{
    str.erase(str.find(delimiter), (str.length() - str.find(delimiter)));
    return (str);
}

std::string split_string_end(std::string str, std::string delimiter)
{
    str.erase(0, str.find(delimiter) + 1);
    return (str);
}