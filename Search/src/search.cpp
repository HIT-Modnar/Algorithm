#include "Header.h"

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int divtwo(int m, int n) {
    return (m + n) / 2;
}

void QuickSort(int list[], int m, int n) {
    if(m < n) {
        int i = m + 1, j = n, k = divtwo(m, n);
        int key = list[k];
        swap(list[m], list[k]);
        while(i <= j) {
            while(i <= n && list[i] <= key) i++;
            while(j >= m && list[j] > key) j--;
            if(i < j) swap(list[i], list[j]);
        }
        swap(list[m], list[j]);
        QuickSort(list, m, j - 1);
        QuickSort(list, j + 1, n);
    }
}

int BinarySearch(int list[], int m, int n, int data) {
    int mid;
    while(m <= n) {
        mid = divtwo(m, n);
        if(list[mid] > data) n = mid - 1;
        else if(list[mid] < data) m = mid + 1;
        else return mid;
    }
    return -1;
}
