// Author : Modnar
// Date   : 2019-06-23
// Copyright (C) 2019 Modnar. All rights reserved.

#include <map>
#include <string>

class TrieNode {
public:
    TrieNode() : _size(0), _frequency(0) { }
    void insert(const std::string &word);
    int contains(const std::string &word);
    int size();

private:
    int _size;
    int _frequency;
    std::map<char, TrieNode*> children;
};
