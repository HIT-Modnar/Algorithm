// Name   : B-Tree
// Author : Modnar
// Date   : 2019-05-08
// Copyright (C) 2019 Modnar. All rights reserved.

#ifndef B_TREE_HPP
#define B_TREE_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Every node contains 2*MAX_SIZE-1 keys and 2*MAX_SIZE children.
const int MAX_SIZE = 4;

typedef int Key;
typedef std::string Value;

class Data {
public:
    Key key;
    Value value;
};

class Node {
public:
    Node() { dataset = std::vector<std::shared_ptr<Data>>(2*MAX_SIZE-1); 
             children = std::vector<std::shared_ptr<Node>>(2*MAX_SIZE); }
    std::vector<std::shared_ptr<Data>> dataset;
    std::vector<std::shared_ptr<Node>> children;
    bool leaf;
    int n;
};

extern void B_TREE_CREATE(std::shared_ptr<Node> &T);
extern void B_TREE_SPLIT_CHILD(std::shared_ptr<Node> &x, int i, 
        std::shared_ptr<Node> &y);
extern void B_TREE_INSERT(std::shared_ptr<Node> &T, std::shared_ptr<Data> &K);
extern void B_TREE_INSERT_NONFULL(std::shared_ptr<Node> &T, std::shared_ptr<Data> &K);
extern void B_TREE_DELETE(std::shared_ptr<Node> &T, Key K);
extern void B_TREE_UNION(std::shared_ptr<Node> &x, int i);
extern std::shared_ptr<Data> B_TREE_SEARCH(std::shared_ptr<Node> &T, Key K);

#endif /* B_TREE_HPP */
