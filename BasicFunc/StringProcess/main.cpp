// Name   : main.cpp
// Author : Modnar
// Date   : 2019-05-11

#include <iostream>

#include "StringProcess.hpp"

int main(int argc, char *argv[]) {
    std::string str = "  Hello, world!  ";
    std::cout << "Test for split:" << std::endl;
    auto sub_str_list = split(str);
    for (auto var : sub_str_list)
        std::cout << var << "_";
    std::cout << std::endl;
    sub_str_list = split(str, ",");
    for (auto var : sub_str_list)
        std::cout << var << "_";
    std::cout << std::endl;
    std::cout << "Test for trim:" << std::endl;
    auto res = trim(str);
    std::cout << res << std::endl;
    std::cout << "Combination test:" << std::endl;
    for (auto var : sub_str_list)
        std::cout << trim(var) << " ";
    std::cout << std::endl;
    return 0;
}
