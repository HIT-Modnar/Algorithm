// Name   : B-Tree
// Author : Modnar
// Date   : 2019-05-08
// Copyright (C) 2019 Modnar. All rights reserved.

#include <fstream>
#include <iostream>

#include "Tree.hpp"

/**
 * Test for B-Tree.
 */
int main(int argc, char *argv[]) {
    std::shared_ptr<Node> B_TREE;
    B_TREE_CREATE(B_TREE);
    int N = 1000000;
    std::vector<std::shared_ptr<Data>> dataVec;
    std::ifstream is("data.txt");
    for (int i = 0; i < N; ++i) {
        dataVec.push_back(std::make_shared<Data>());
        is >> dataVec[i]->key;
        is >> dataVec[i]->value;
    }
    is.close();
    for (int i = 0; i < N; ++i) {
        // std::cout << i << std::endl;
        B_TREE_INSERT(B_TREE, dataVec[i]);
    }
    for (int i = 0; i < 10; ++i) {
        auto node = B_TREE_SEARCH(B_TREE, i);
        if (node == nullptr)
            continue;
        std::cout << node->key << " " << node->value << std::endl;
    }
    return 0;
}
