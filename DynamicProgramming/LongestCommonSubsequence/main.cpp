// Name   : main.hpp
// Author : Modnar
// Date   : 2019-05-15
// Copyright (C) 2019 Modnar. All rights reserved.

// Modified : 2019-06-18 Modnar : Moved the code to DynamicProgramming.

#include <iostream>

#include "LCS.hpp"

int main(int argc, const char *argv[]) {
    std::string str1 = "Hello", str2 = "hello";
    std::cout << "Hello, hello:\nLCS: " << LCS(str1, str2) << std::endl 
              << "LCS_STR: " << LCS_STR(str1, str2, true) << std::endl;
    str1 = "123456", str2 = "224466";
    std::cout << "\n123456, 224466:\nLCS_STR: " << LCS_STR(str1, str2) << std::endl;
    return 0;
}
