// Author : Modnar
// Date   : 2019-06-18
// Copyright (C) 2019 Modnar. All rights reserved.

#include <iostream>
#include <string>

const int MAX_SIZE = 100;

template <typename T>
int minimum(const T &a, const T &b, const T &c) {
    return std::min(a, std::min(b, c));
}

// Compute the edit distance.
int edit_dist(const std::string &str1, const std::string &str2) {
    int len1 = str1.size(), len2 = str2.size();
    int dis[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= len1; ++i)
        dis[i][0] = i;
    for (int i = 0; i <= len2; ++i)
        dis[0][i] = i;
    for (int i = 1; i <= len1; ++i)
        for (int j = 1; j <= len2; ++j)
            if (str1[i-1] == str2[i-1]) {
                dis[i][j] = dis[i-1][j-1];
            } else {
                dis[i][j] = minimum(dis[i-1][j]+1, dis[i][j-1]+1, dis[i-1][j-1]+1);
            }
    return dis[len1][len2];
}

int main(int argc, const char *argv[]) {
    std::cout << edit_dist("HELLO", "hello") << std::endl;
    std::cout << edit_dist("World", "worlD") << std::endl;
    return 0;
}
