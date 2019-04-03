#include <iostream>
#include <vector>

#include "../test/test.hpp"

// Insertsort
template <typename T> void insertsort(std::vector<T> &vec, int m, int n)
{
    if (m < n) {
        int j;
        for (int i = m+1; i < n; ++i) {
            auto key = vec[i];
            for (j = i-1; j > -1 && key < vec[j]; --j)
                vec[j+1] = vec[j];
            vec[j+1] = key;
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> ivec;
    get_random_seq(ivec);
    insertsort(ivec, 0, ivec.size());
    std::cout << "Insertsort:" << std::endl;
    show_seq(ivec);
    return 0;
}
