// Name   : sort.cpp
// Author : Modnar
// Date   : 2019-03-02
// Copyright (C) 2019 Modnar. All rights reserved.

/**
 * This file implements some sort algorithms to make the ascent order to a 
 * [m, n) sequence. And in the file, all of the sequence is ordered as vector.
 * All the algorithms need three paragrams as the source vector, left bound 
 * and the right bound.
 * For example, you can call a function like this:
 *     modnar::quicksort(vec, 0, vec.size());
 */
#include "Header.h"

// Quicksort
template <typename T> void quicksort(std::vector<T> &vec, int m, int n) 
{
    if (m < n) {
        int i = m + 1, j = n - 1, k = (m + n) / 2;
        auto key = vec[k];
        std::swap(vec[m], vec[k]);
        while (i <= j) {
            while (i <= n-1 && vec[i] <= key) ++i;
            while (j >= m && vec[j] > key) --j;
            if (i < j)
                std::swap(vec[i], vec[j]);
        }
        std::swap(vec[m], vec[j]);
        quicksort(vec, m, j);
        quicksort(vec, j+1, n);
    }
}

// Mergesort
template <typename T> void merge(std::vector<T> &vec, int m, int n)
{
    std::vector<T> tmpVec;
    int mid = (m + n) / 2, i = m, j = mid;
    while (i < mid && j < n) {
        if (vec[i] > vec[j]) tmpVec.push_back(vec[j++]);
        else tmpVec.push_back(vec[i++]);
    }
    while (i < mid) tmpVec.push_back(vec[i++]);
    while (j < n) tmpVec.push_back(vec[j++]);
    for (auto val : tmpVec) 
        vec[m++] = val;
}

template <typename T> void mergesort(std::vector<T> &vec, int m, int n)
{
    if (m < n-1) {
        int mid = (m + n) / 2;
        mergesort(vec, m, mid);
        mergesort(vec, mid, n);
        merge(vec, m, n);
    }
}

// Selectsort
template <typename T> void selectsort(std::vector<T> &vec, int m, int n) 
{
    if (m < n) {
        for (size_t i = m; i < n-1; ++i) {
            size_t k = i;
            for (size_t j = k+1; j <= n-1; ++j) {
                if (vec[k] > vec[j])
                    k = j;
            }
            if (k != i) std::swap(vec[i], vec[k]);
        }
    }
}

// Bubblesort
template <typename T> void bubblesort(std::vector<T> &vec, int m, int n)
{
    if (m < n) {
        for (size_t i = m; i < n-1; ++i)
            for (size_t j = m; j < n-i-1; ++j)
                if (vec[j] > vec[j+1]) std::swap(vec[j], vec[j+1]);
    }
}

// Insertsort
template <typename T> void insertsort(std::vector<T> &vec, int m, int n)
{
    if (m < n) {
        int j;
        for (int i = m+1; i < n; ++i) {
            auto key = vec[i];
            for (j = i-1; j > -1 && key < vec[j]; --j)
                vec[j+1] = vec[j];
            vec[j+1] = key;
        }
    }
}


