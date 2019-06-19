// Author : Modnar
// Date   : 2019-06-18
// Copyright (C) 2019 Modnar. All rights reserved.

#include <iostream>
#include <string>
#include <vector>

const int MAX_CHAR = 256;
const int MAX_SIZE = 256;

void PreBMBadChar(const std::string &pattern, std::vector<std::size_t> &badchar) {
    badchar = std::vector<std::size_t>(MAX_CHAR, pattern.size());
    std::size_t length = pattern.size();
    for (std::size_t i = 0; i < length - 1; ++i)
        badchar[pattern[i]] = length - 1 - i;
}

void Suffix(const std::string &pattern, std::vector<std::size_t> &suffix) {
    std::size_t length = pattern.size();
    suffix = std::vector<std::size_t>(length);
    suffix[length-1] = length;
    for (int i = length-2; i >= 0; --i) {
        int k = i;
        while (k >= 0 && pattern[k] == pattern[length-1-i+k]) {
            --k;
        }
        suffix[i] = i - k;
    }
}

void Suffix_new(const std::string &pattern, std::vector<std::size_t> &suffix) {
    std::size_t length = pattern.size();
    suffix = std::vector<std::size_t>(length);
    suffix[length-1] = length;
    int g = length - 1, i, f;
    for (i = length-2; i >= 0; --i) {
        if (i > g && suffix[i+length-1-f] < i-g) {
            suffix[i] = suffix[i+length-1-f];
        } else {
            if (i < g) 
                g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g+length-1-f])
                --g;
            suffix[i] = f - g;
        }
    }
}

void PreBMGoodSuffix(const std::string &pattern, std::vector<std::size_t> &goodsuffix) {
    int i, j = 0;
    std::size_t length = pattern.size();
    std::vector<std::size_t> suffix;
    //Suffix(pattern, suffix);
    Suffix_new(pattern, suffix); // Improvement of Suffix function.
    for (i = length-1; i >= 0; --i) 
        if (i+1 == suffix[i]) 
            for (; j < length-1-i; ++j)
                if (length == goodsuffix[j])
                    goodsuffix[j] = length - 1 - i;
    for (i = 0; i < length-2; ++i)
        goodsuffix[length-1-suffix[i]] = length - 1 - i;
}

int BoyerMoore(const std::string &source, const std::string &pattern) {
    int i, j = 0;
    std::size_t m = pattern.size(), n = source.size();
    std::vector<std::size_t> badchar, goodsuffix(MAX_SIZE);
    PreBMBadChar(pattern, badchar);
    PreBMGoodSuffix(pattern, goodsuffix);
    while (j <= n-m) {
        for (i = m-1; i >= 0 && pattern[i] == source[i+j]; --i) 
            ;
        if (i < 0) {
            return j;
        } else {
            j += std::max(badchar[source[i+j]]-m+1+i, goodsuffix[i]);
        }
    }
    return -1;
}

// Example:
//   012345678901234567890123   ACTION      Pos     STRATEGY
//   HERE IS A SIMPLE EXAMPLE   
//   EXAMPLE                    SHIFT: 7    0       BAD_CHAR
//          EXAMPLE             SHIFT: 2    7       BAD_CHAR
//            EXAMPLE           SHIFT: 6    9      GOOD_SUFFIX
//                  EXAMPLE     SHIFT: 2    15      BAD_CHAR
//                    EXAMPLE   BINGO!      17  
int main(int argc, const char *argv[]) {
    std::cout << BoyerMoore("HERE IS A SIMPLE EXAMPLE", "EXAMPLE") << std::endl;
    return 0;
}
