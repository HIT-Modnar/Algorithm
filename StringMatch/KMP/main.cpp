// Author : Modnar
// Date   : 2019-04-07
// Copyright (C) 2019 Modnar. All rights reserved.

#include <iostream>
#include <string>
#include <vector>

// Implementation in C
void make_next(char *pattern, int *next, int len) {
    next[0] = -1;
    int k = -1;
    for (int i = 1; i < len; ++i) {
        while (k > -1 && pattern[k+1] != pattern[i]) 
            k = next[k];
        if (pattern[k+1] == pattern[i]) 
            k++;
        next[i] = k;
    }
}

void search(char *source, int slen, char *pattern, int len) {
    int *next = (int *)malloc(len);
    make_next(pattern, next, len);
    int k = -1;
    for (int i = 0; i < slen; i++) {
        while (k > -1 && pattern[k+1] != source[i]) 
            k = next[k];
        if (pattern[k+1] == source[i])
            ++k;
        if (k == len - 1) {
            std::cout << "Position: " << i-len+1 << std::endl;
            k = -1;
            i = i - len + 1;
        }
    }
}

// Implementation in C++11
std::vector<int> make_next(const std::string &pattern) {
    std::vector<int> next;
    next.push_back(-1);
    int k = -1;
    for (int i = 1; i < pattern.size(); ++i) {
        while (k > -1 && pattern[k+1] != pattern[i])
            k = next[k];
        if (pattern[k+1] == pattern[i])
            ++k;
        next.push_back(k);
    }
    return next;
}

void search(const std::string &source, const std::string &pattern) {
    std::vector<int> next = make_next(pattern);
    int k = -1;
    auto len = pattern.size();
    for (int i = 0; i < source.size(); ++i) {
        while (k > -1 && pattern[k+1] != source[i]) 
            k = next[k];
        if (pattern[k+1] == source[i])
            ++k;
        if (k == len - 1) {
            std::cout << "Position: " << i-len+1 << std::endl;
            k = -1;
            i = i - len + 1;
        }
    }
}

int main() {
//    char source[] = "BBC ABCDAB ABCDABCDABDE";
//    char pattern[] = "ABCDABD";
//    search(source, 36, pattern, 7);
    std::string source("BBC ABCDAB ABCDABCDABDE");
    std::string pattern("ABCDABD");
    search(source, pattern);
    return 0;
}
