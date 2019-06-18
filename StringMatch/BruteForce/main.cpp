// Author : Modnar
// Date   : 2019-06-18
// Copyright (C) 2019 Modnar. All rights reserved.

#include <iostream>
#include <string>

// Algorithm: Brute-Force
int search(const std::string &source, const std::string &pattern) {
    if (pattern.size() > source.size() || pattern.size() == 0)
        return -1;
    for (std::size_t i = 0; i < source.size(); ++i) {
        std::size_t j = 0, k = i;
        for (; j < pattern.size() && k < source.size(); ++j, ++k) {
            if (source[k] != pattern[j])
                break;
        }
        if (j == pattern.size())
            return i;
    }
    return -1;
}

int main(int argc, const char *argv[]) {
    std::cout << search("BBCABCDABABCDABDABDE", "ABCDABD") << std::endl;
    std::cout << search("BBCABCDABABCCABDABDE", "ABCDABD") << std::endl;
    return 0;
}
