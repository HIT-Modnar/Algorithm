#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>

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

void search(char *str, int slen, char *pattern, int len) {
    int *next = (int *)malloc(len);
    make_next(pattern, next, len);
    int k = -1;
    for (int i = 0; i < slen; i++) {
        while (k > -1 && pattern[k+1] != str[i]) 
            k = next[k];
        if (pattern[k+1] == str[i])
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

void search(const std::string &str, const std::string &pattern) {
    std::vector<int> next = make_next(pattern);
    int k = -1;
    auto len = pattern.size();
    for (int i = 0; i < str.size(); ++i) {
        while (k > -1 && pattern[k+1] != str[i]) 
            k = next[k];
        if (pattern[k+1] == str[i])
            ++k;
        if (k == len - 1) {
            std::cout << "Position: " << i-len+1 << std::endl;
            k = -1;
            i = i - len + 1;
        }
    }
}

int main() {
//    char str[] = "BBC ABCDAB ABCDABCDABDE";
//    char pattern[] = "ABCDABD";
//    search(str, 36, pattern, 7);
    std::string str("BBC ABCDAB ABCDABCDABDE");
    std::string pattern("ABCDABD");
    search(str, pattern);
    return 0;
}
