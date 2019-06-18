// Author : Modnar
// Date   : 2019-06-18
// Copyright (C) 2019 Modnar. All rights reserved.

#include <iostream>
#include <string>
#include <vector>

const std::size_t MAX_SIZE = 26;

// Algorithm: Horspool
//
// @param source The source string which is need to be matched.
// @param pattern The pattern string.
// @return the pattern string's index in source string if it exists, otherwise 
//   return -1.
// 
// Note:
//   If you prefer using basic array, you can initialize array 'next' like comment's 
// content.
int search(std::string source, std::string pattern) {
    std::size_t length = pattern.size();
    if (source.size() < length || length == 0)
        return -1;
//    std::size_t next[MAX_SIZE] = {0};
    std::vector<std::size_t> next(MAX_SIZE, length);
    std::string substr = pattern.substr(0, length-1);
//    for (std::size_t i = 0; i < MAX_SIZE; ++i) {
//        char ch = 'A' + i;
//        std::size_t pos = substr.find_last_of(ch);
//        if (pos == std::string::npos)
//            next[i] = length;
//        else
//            next[i] = length - pos - 1;
//    }
    for (std::size_t i = 0; i < length-1; ++i) {
        next[pattern[i]-'A'] = length - i - 1;
    }
    std::size_t pos = 0, limit = source.size();
    int i = length-1;
    char ch = source[pos+i];
    while (pos+i < limit && i >= 0) {
        if (pattern[i] != source[pos+i]) {
            // std::cout << "SHIFT:" << next[ch-'A'] << std::endl;
            pos += next[ch-'A'];
            i = length - 1;
            ch = source[pos+i];
            continue;
        } 
        --i;
    }
    return (i < 0 ? pos : -1);
}

// Test for the Algorithm of Horspool's implementation.
// Example:
//   BBCABCDABABCDABDABDE
//   ABCDABD              SHIFT: 3
//      ABCDABD           SHIFT: 2
//        ABCDABD         SHIFT: 4
//            ABCDABD     BINGO!
int main(int argc, char *argv[]) {
    std::cout << search("BBCABCDABABCDABDABDE", "ABCDABD") << std::endl;
    return 0;
}
