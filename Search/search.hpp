// Name   : search.h
// Author : Modnar
// Date   : 2019-05-10
// Copyright (C) 2019 Modnar. All rights reserved.

#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>

/**
 * Get the key's index/position in vector using binary search:
 *   If the parameter's value of insert is false, get -1 when the vector doesn't 
 *   contains key. If the parameter's value of insert is true, get the position
 *   where the key should be inserted.
 * 
 * For example: 
 *   The vector is: 6 9 19 19 45 50 52 60 60 64 74 76 77 78 84 87 90 92 96 100 and
 *   key is 10.
 *   If parameter's value of insert is false, get -1. If the value is true, get 2.
 *
 *   The vector is: 6 9 10 19 45 50 52 60 60 64 74 76 77 78 84 87 90 92 96 100 and
 *   key is 10.
 *   Get 2 whether the insert's value is true or not.
 *
 * Warning:
 *   If want the function could work normally, make sure the vector's content is an 
 *   ascending sequence.
 * 
 * @param: ivec: The vector need to be searched.
 * @param: key: The key to search.
 * @param: insert: The choice of searching's pattern. 
 * @return the index or position of key in ivec.
 */
extern int binary_search(const std::vector<int> &ivec, int key, bool insert = false);

#endif
