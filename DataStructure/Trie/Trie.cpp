// Author : Modnar
// Date   : 2019-06-23
// Copyright (C) 2019 Modnar. All rights reserved.

#include "Trie.hpp"

void TrieNode::insert(const std::string &word) {
    if (word == "")
        return;
    TrieNode *p = this;
    for (char ch : word) {
        if (p->children.find(ch) == p->children.end()) {
            p->children[ch] = new TrieNode();
            p = p->children[ch];
        } else {
            p = p->children[ch];
        }
    }
    ++p->_frequency;
    if (p->_frequency == 1)
        ++this->_size;
}

int TrieNode::contains(const std::string &word) {
    TrieNode *p = this;
    std::size_t i = 0;
    for (; i <word.size(); ++i) {
        char ch = word[i];
        if (p->children.find(ch) == p->children.end()) {
            break;
        } else {
            p = p->children[ch];
        }
    }
    return i == word.size() ? p->_frequency : 0;
}

int TrieNode::size() {
    return this->_size;
}
