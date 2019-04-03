#include <iostream>
#include <vector>

#include "../test/test.hpp"

// Bubblesort
template <typename T> void bubblesort(std::vector<T> &vec, int m, int n)
{
    if (m < n) {
        for (size_t i = m; i < n-1; ++i)
            for (size_t j = m; j < n-i-1; ++j)
                if (vec[j] > vec[j+1]) std::swap(vec[j], vec[j+1]);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> ivec;
    get_random_seq(ivec);
    bubblesort(ivec, 0, ivec.size());
    std::cout << "Bubblesort:" << std::endl;
    show_seq(ivec);
    return 0;
}
