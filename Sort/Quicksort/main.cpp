#include <iostream>
#include <vector>

#include "../test/test.hpp"

// Quicksort
template <typename T> void quicksort(std::vector<T> &vec, int m, int n) 
{
    if (m < n) {
        int i = m + 1, j = n - 1, k = (m + n) / 2;
        auto key = vec[k];
        std::swap(vec[m], vec[k]);
        while (i <= j) {
            while (i <= n-1 && vec[i] <= key) ++i;
            while (j >= m && vec[j] > key) --j;
            if (i < j)
                std::swap(vec[i], vec[j]);
        }
        std::swap(vec[m], vec[j]);
        quicksort(vec, m, j);
        quicksort(vec, j+1, n);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> ivec;
    get_random_seq(ivec);
    quicksort(ivec, 0, ivec.size());
    std::cout << "Quicksort:" << std::endl;
    show_seq(ivec);
    return 0;
}
