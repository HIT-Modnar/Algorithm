// Name   : B-Tree
// Author : Modnar
// Date   : 2019-05-08
// Copyright (C) 2019 Modnar. All rights reserved.

#include "Tree.hpp"

void B_TREE_CREATE(std::shared_ptr<Node> &T) {
    T = std::make_shared<Node>();
    T->leaf = true;
    T->n = 0;
}

void B_TREE_SPLIT_CHILD(std::shared_ptr<Node> &x, int i, std::shared_ptr<Node> &y) {
    auto z = std::make_shared<Node>();
    z->leaf = y->leaf;
    z->n = MAX_SIZE - 1;
    for (int j = 0; j < MAX_SIZE-1; ++j) {
        z->dataset[j] = y->dataset[MAX_SIZE+j];
    }
    if (!y->leaf) {
        for (int j = 0; j < MAX_SIZE; ++j) 
            z->children[j] = y->children[MAX_SIZE+j];
    }
    y->n = MAX_SIZE - 1;
    for (int j = x->n; j > i; --j) 
        x->children[j+1] = x->children[j];
    x->children[i+1] = z;
    for (int j = x->n; j > i; --j)
        x->dataset[j] = x->dataset[j-1];
    x->dataset[i] = y->dataset[MAX_SIZE-1];
    ++x->n;
}

void B_TREE_INSERT(std::shared_ptr<Node> &T, std::shared_ptr<Data> &K) {
    if (T->n == 2*MAX_SIZE-1) {
        auto s = std::make_shared<Node>(), r = T;
        s->leaf = false;
        s->n = 0;
        s->children[0] = r;
        T = s;
        B_TREE_SPLIT_CHILD(s, 0, r);
        B_TREE_INSERT_NONFULL(s, K);
    } else {
        B_TREE_INSERT_NONFULL(T, K);
    }
}

void B_TREE_INSERT_NONFULL(std::shared_ptr<Node> &x, std::shared_ptr<Data> &K) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && K->key < x->dataset[i]->key) {
            x->dataset[i+1] = x->dataset[i];
            --i;
        }
        ++i;
        x->dataset[i] = K;
        ++x->n;
    } else {
        while (i >= 0 && K->key < x->dataset[i]->key) 
            --i;
        ++i;
        if (x->children[i]->n == 2*MAX_SIZE-1) {
            B_TREE_SPLIT_CHILD(x, i, x->children[i]);
            if (K->key > x->dataset[i]->key)
                ++i;
        }
        B_TREE_INSERT_NONFULL(x->children[i], K);
    }
}

std::shared_ptr<Data> B_TREE_SEARCH(std::shared_ptr<Node> &x, Key K) {
    int i = 0;
    while (i < x->n && K > x->dataset[i]->key)
        ++i;
    if (i < x->n && K == x->dataset[i]->key)
        return x->dataset[i];
    if (x->leaf)
        return nullptr;
    else 
        return B_TREE_SEARCH(x->children[i], K);
}

void B_TREE_DELETE(std::shared_ptr<Node> &x, Key K) {
    int i = 0;
    while (i < x->n && K > x->dataset[i]->key) 
        ++i;
    if (i < x->n && K == x->dataset[i]->key) {
        if (x->leaf) {
            for (int j = i; j < x->n-1; ++j)
                x->dataset[j] = x->dataset[j+1];
            --x->n;
        } else if (i+1 <= x->n) {
            auto y1 = x->children[i], y2 = x->children[i+1];
            int t;
            if (y1->n >= MAX_SIZE) {
                t = y1->n - 1;
                x->dataset[i] = y1->dataset[t];
                B_TREE_DELETE(y1, y1->dataset[t]->key);
            } else if (y2->n >= MAX_SIZE) {
                x->dataset[i] = y2->dataset[0];
                B_TREE_DELETE(y2, y2->dataset[0]->key);
            } else {
                B_TREE_UNION(x, i);
                B_TREE_DELETE(x->children[i], K);
            }
        } else {
            std::cout << "Error when remove!" << std::endl;
        }
    } else if (x->leaf) {
        std::cout << "Nothing was changed!" << std::endl;
    } else {
        if (x->children[i]->n >= MAX_SIZE) {
            B_TREE_DELETE(x->children[i], K);
        } else {
            if (i+1 <= x->n && x->children[i+1]->n < MAX_SIZE) {
                B_TREE_UNION(x, i);
            } else if (i+1 <= x->n) {
                auto y1 = x->children[i], y2 = x->children[i+1];
                y1->dataset[y1->n] = x->dataset[i];
                ++y1->n;
                x->dataset[i] = y2->dataset[0];
                y1->children[y1->n] = y2->children[0];
                int t;
                for (t = 0; t < y2->n-1; ++t) {
                    y2->dataset[t] = y2->dataset[t+1];
                    y2->children[t] = y2->children[t+1];
                }
                y2->children[t] = y2->children[t+1];
                --y2->n;
            } else if (i-1 >= 0 && x->children[i-1]->n < MAX_SIZE) {
                B_TREE_UNION(x, i-1);
                --i;
            } else if (i-1 >= 0) {
                auto y1 = x->children[i], y2 = x->children[i-1];
                int t;
                for (t = y1->n; t > 0; --t) {
                    y1->dataset[t] = y1->dataset[t-1];
                    y1->children[t+1] = y1->children[t];
                }
                y1->children[t+1] = y1->children[t];
                y1->dataset[0] = x->dataset[i];
                ++y1->n;
                x->dataset[i] = y2->dataset[y2->n-1];
                y1->children[0] = y2->children[y2->n];
                --y2->n;
                B_TREE_DELETE(x->children[i], K);
            }
            B_TREE_DELETE(x->children[i], K);
        }
    }
}

void B_TREE_UNION(std::shared_ptr<Node> &x, int i) {
    auto y1 = x->children[i], y2 = x->children[i+1];
    int n1 = y1->n, n2 = y2->n;
    y1->dataset[n1] = x->dataset[i];
    int a = 0;
    for (; a < n2; ++a) {
        y1->dataset[n1+a+1] = y2->dataset[a];
        y1->children[n1+a+1] = y2->children[a];
    }
    y1->children[n1+a+1] = y2->children[a];
    for (int t = i; t < x->n-1; ++t) {
        x->dataset[t] = x->dataset[t+1];
        x->children[t+1] = x->children[t+2];
    }
    --x->n;
    y1->n = n1 + n2 + 1;
    y2 = nullptr;
}
