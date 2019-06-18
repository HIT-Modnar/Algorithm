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
int search(const std::string &source, const std::string &pattern) {
    std::size_t length = pattern.size();
    if (source.size() < length || length == 0)
        return -1;
    std::vector<std::size_t> next(MAX_SIZE, length);
    std::string substr = pattern.substr(0, length-1);
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

// Implementation from web.
// Source: https://blog.csdn.net/khwkhwkhw/article/details/51288502
// Modified by Modnar at 2019-06-18.
int Horspool(const std::string &T, const std::string &P) {
    int n = T.size();
    int m = P.size();   
    std::vector<int> table(96, m); //以字母表中可打印字符为索引的数组

    for (int i = 0; i < m - 1; i++) {
        table[P[i]-32] = m - 1 - i; //模式串中每个字符的移动距离，从左至右扫描模式，相同字符的最后一次改写恰好是该字符在模式串的最右边
    }

    int i = m - 1;
    while(i <= n-1) {
        int k = 0;
        while (k <= m-1 && P[m-1-k] == T[i-k])
            k++;

        if (k == m)
            return i - m + 1; //匹配成功，返回索引
        else
            i += table[T[i]-32]; //模式串向右移动
    }

    return -1; //匹配失败
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
    std::cout << Horspool("BBCABCDABABCDABDABDE", "ABCDABD") << std::endl;
    return 0;
}
