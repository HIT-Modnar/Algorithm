// Name   : main.cpp
// Author : Modnar
// Date   : 2019-05-11
// Copyright (C) 2019 Modnar. All rights reserved.

#include "../search.hpp"
#include "../test.hpp"

/**
 * Test the function of insertion search.
 */
int main(int argc, char *argv[]) {
    auto ivec = get_asce_vec();
    std::cout << "The raw ascending sequence:" << std::endl;
    show_vec(ivec);
    std::cout << "Search the key's index:" << std::endl;
    std::cout << insertion_search(ivec, 10) << std::endl;
    std::cout << "Search the key's insert position:" << std::endl;
    std::cout << insertion_search(ivec, 10, true) << std::endl;
    return 0;
}
