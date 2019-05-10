// Name   : BinarySearch.cpp
// Author : Modnar
// Date   : 2019-05-10

#include "../search.hpp"

int binary_search(const std::vector<int> &ivec, int key, bool insert) {
    int low = 0, high = ivec.size()-1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (key > ivec[mid]) {
            low = mid + 1;
        } else if (key < ivec[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    if (insert)
        return low;
    return -1;
}
