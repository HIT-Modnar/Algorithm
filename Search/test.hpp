// Name   : test.hpp
// Author : Modnar
// Date   : 2019-05-10
// Coright (C) 2019 Modnar. All rights reserved.

#ifndef TEST_HPP
#define TEST_HPP

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// The max size of the vector to test.
const int TEST_MAX_SIZE = 20;

/**
 * Get a random int vector.
 *
 * @param: int low(0): The minimum value of the target vector's content.
 * @param: int high(100): The maximum value of the target vector's content.
 * @param: int size(TEST_MAX_SIZE): The size of the target vector's size.
 * @return: The target vector.
 */
extern std::vector<int> get_rand_vec(int low = 0, int high = 100, 
        int size = TEST_MAX_SIZE) {
    static std::default_random_engine e(time(nullptr));
    static std::uniform_int_distribution<int> dis(low, high);
    std::vector<int> ivec;
    for (size_t i = 0; i < size; ++i)
        ivec.push_back(dis(e));
    return ivec;
}

/**
 * Get a random int vector sorted as an ascending sequence.
 *
 * @param: int low(0): The minimum value of the target vector's content.
 * @param: int high(100): The maximum value of the target vector's content.
 * @param: int size(TEST_MAX_SIZE): The size of the target vector's size.
 * @return: The target vector.
 */
extern std::vector<int> get_asce_vec(int low = 0, int high = 100,
        int size = TEST_MAX_SIZE) {
    auto ivec = get_rand_vec(low, high, size);
    std::sort(ivec.begin(), ivec.end());
    return ivec;
}

/**
 * Show the vector's content.
 *
 * @param: const std::vecotr<int> &ivec: The source vector to show.
 * @param: char delim: The delimiter of the vector to show.
 * @param: std::ostream &os: The output stream.
 */
extern void show_vec(const std::vector<int> &ivec, char delim = ' ', 
        std::ostream &os = std::cout) {
    for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
        os << *iter << delim;
    os << std::endl;
}

#endif /* TEST_HPP */
