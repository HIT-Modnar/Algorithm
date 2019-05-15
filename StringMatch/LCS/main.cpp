// Name   : main.hpp
// Author : Modnar
// Date   : 2019-05-15

#include <iostream>

#include "LCS.hpp"

int main(int argc, char *argv[]) {
    std::string str1 = "Hello", str2 = "hello";
    std::cout << LCS(str1, str2) << std::endl;
    std::cout << LCS_STR(str1, str2) << std::endl;
    return 0;
}
