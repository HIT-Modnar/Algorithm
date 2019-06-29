// Author : Modnar
// Date   : 2019-06-23
// Copyright (C) 2019 Modnar. All rights reserved.

#include <fstream>
#include <iostream>

#include "Trie.hpp"

int main(int argc, const char *argv[]) {
    std::string filepath = "input.txt", line;
    std::ifstream is(filepath);
    if (!is) {
        std::cerr << "Error when open file: " << filepath << "!" << std::endl;
        exit(1);
    }
    TrieNode TrieTree = TrieNode();
    while (getline(is, line)) {
        TrieTree.insert(line);
    }
    std::cout << TrieTree.contains("To") << std::endl;
    std::cout << TrieTree.contains("world") << std::endl;
    std::cout << TrieTree.contains("be") << std::endl;
    std::cout << TrieTree.size() << std::endl;
    return 0;
}
