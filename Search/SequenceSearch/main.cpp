// Name   : main.cpp
// Author : Modnar
// Date   : 2019-05-11
// Copyright (C) 2019 Modnar. All rights reserved.

#include "../search.hpp"
#include "../test.hpp"

/**
 * Test the function of sequence search.
 */
int main(int argc, char *argv[]) {
    auto ivec = get_rand_vec();
    std::cout << "The raw ascending sequence:" << std::endl;
    show_vec(ivec);
    std::cout << "Search the key's index:" << std::endl;
    std::cout << sequence_search(ivec, 10) << std::endl;
    return 0;
}
