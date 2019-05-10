// Name   : main.cpp
// Author : Modnar
// Date   : 2019-05-10
// Copyright (C) 2019 Modnar. All rights reserved.

#include "../search.hpp"
#include "../test.hpp"

/**
 * Test the function of binary search.
 * 
 * Test the function for two aspects:
 * 1. Parameter's value of insert is false.
 * 2. Parameter's value of insert is true. 
 */
int main(int argc, char *argv[]) {
    auto ivec = get_asce_vec();
    std::cout << "The raw ascending sequence:" << std::endl;
    show_vec(ivec);
    std::cout << "Search the key's index:" << std::endl;
    std::cout << binary_search(ivec, 10) << std::endl;
    std::cout << "Search the key's insert position:" << std::endl;
    std::cout << binary_search(ivec, 10, true) << std::endl;
    return 0;
}
