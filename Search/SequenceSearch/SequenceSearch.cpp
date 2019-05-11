// Name   : SequenceSearch.cpp
// Author : Modnar
// Date   : 2019-05-11

#include "../search.hpp"

int sequence_search(const std::vector<int> &ivec, int key) {
    for (int i = 0; i < ivec.size(); ++i)
        if (ivec[i] == key)
            return i;
    return -1;
}
