#ifndef HELPERS_HPP
# define HELPERS_HPP

#include <iostream>
#include <algorithm>

template <typename T>
struct  check {
    bool    error;
    T       data;
};

std::string remove_space(std::string str);
std::string split_string(std::string str, std::string delimiter);
std::string split_string_end(std::string str, std::string delimiter);
void        down(std::string message);

#endif