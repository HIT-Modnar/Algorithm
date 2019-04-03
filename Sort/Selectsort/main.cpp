#include <iostream>
#include <vector>

#include "../test/test.hpp"

// Selectsort
template <typename T> void selectsort(std::vector<T> &vec, int m, int n) 
{
    if (m < n) {
        for (size_t i = m; i < n-1; ++i) {
            size_t k = i;
            for (size_t j = k+1; j <= n-1; ++j) {
                if (vec[k] > vec[j])
                    k = j;
            }
            if (k != i) std::swap(vec[i], vec[k]);
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> ivec;
    get_random_seq(ivec);
    selectsort(ivec, 0, ivec.size());
    std::cout << "Selectsort:" << std::endl;
    show_seq(ivec);
    return 0;
}
