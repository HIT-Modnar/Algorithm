#include <iostream>
#include <vector>

#include "../test/test.hpp"

// Mergesort
template <typename T> void merge(std::vector<T> &vec, int m, int n)
{
    std::vector<T> tmpVec;
    int mid = (m + n) / 2, i = m, j = mid;
    while (i < mid && j < n) {
        if (vec[i] > vec[j]) tmpVec.push_back(vec[j++]);
        else tmpVec.push_back(vec[i++]);
    }
    while (i < mid) tmpVec.push_back(vec[i++]);
    while (j < n) tmpVec.push_back(vec[j++]);
    for (auto val : tmpVec) 
        vec[m++] = val;
}

template <typename T> void mergesort(std::vector<T> &vec, int m, int n)
{
    if (m < n-1) {
        int mid = (m + n) / 2;
        mergesort(vec, m, mid);
        mergesort(vec, mid, n);
        merge(vec, m, n);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> ivec;
    get_random_seq(ivec);
    mergesort(ivec, 0, ivec.size());
    std::cout << "Mergesort:" << std::endl;
    show_seq(ivec);
    return 0;
}
