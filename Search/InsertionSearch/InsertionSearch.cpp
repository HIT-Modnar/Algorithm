// Name   : InsertionSearch.cpp
// Author : Modnar
// Date   : 2019-05-11

#include "../search.hpp"

int insertion_search(const std::vector<int> &ivec, int key, bool insert) {
    int low = 0, high = ivec.size()-1;
    while (low <= high) {
        int mid = low + (key - ivec[low]) / (ivec[high] - ivec[low]) * (high - low);
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
