#ifndef TEST_H
#define TEST_H

#include <vector>
#include <random>

const int TEST_SIZE = 20;

extern void get_random_seq(std::vector<int> &ivec, int beg = 0, int end = 100);

void get_random_seq(std::vector<int> &ivec, int beg, int end) {
    static std::default_random_engine e(time(nullptr));
    static std::uniform_int_distribution<int> dis(beg, end);
    ivec.clear();
    for (size_t i = 0; i < TEST_SIZE; ++i)
        ivec.push_back(dis(e));
}

void show_seq(const std::vector<int> &ivec) {
    for (size_t i = 0; i < ivec.size(); ++i)
        std::cout << ivec[i] << " ";
    std::cout << std::endl;
}

#endif /* TEST_H */
