// Name   : LCS.cpp
// Author : Modnar
// Date   : 2019-05-15

#include <iostream> // TODO

#include "LCS.hpp"

typedef struct element {
    int length;
    int direction;
} Element;

Element matrix[MAX_SIZE][MAX_SIZE];

int LCS(const std::string &str1, const std::string &str2) {
    for (int i = 0; i < str1.size(); ++i)
        for (int j = 0; j < str2.size(); ++j) {
            matrix[i][j].length = 0;
            matrix[i][j].direction = 1;
        }
    for (int i = 0; i < str1.size(); ++i)
        for (int j = 0; j < str2.size(); ++j) {
            if (str1[i] == str2[j]) {
                matrix[i+1][j+1].length = matrix[i][j].length + 1;
                matrix[i+1][j+1].direction = 0;
            } else {
                matrix[i+1][j+1].length = std::max(matrix[i][j+1].length, matrix[i+1][j].length);
                matrix[i+1][j+1].direction = matrix[i][j+1].length > matrix[i+1][j].length ? 1 : -1;
            }
        }
    return matrix[str1.size()][str2.size()].length;
}

std::string LCS_STR(const std::string &str1, const std::string &str2, bool still) {
    if (!still)
        LCS(str1, str2);
    std::string res("");
    int i = str1.size(), j = str2.size();
    while (i != 0 && j != 0) {
        if (matrix[i][j].direction == 0) {
            res += str1[i-1];
            --i; --j;
        } else if (matrix[i][j].direction == 1) {
            --i;
        } else {
            --j;
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}
