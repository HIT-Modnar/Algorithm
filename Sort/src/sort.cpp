// 排序算法实现
// Written by: Modnar.
// Edit Date: 2018.7.2
/*
 * 对于每个排序函数:
 *   函数输入:
 *     list[]: 需要进行排序的数组
 *     m: 数组中需要进行排序的第一个元素下标(起始元素下标)
 *     n: 数组中需要进行排序的最后一个元素的下标(终止元素下标)
 *
 *   函数返回:
 *     完成升序排列修改的list数组
 */
#include "Header.h"

/*
 * 交换两个整数的值
 *
 * 函数输入:
 *   需要交换变量值的两个整数变量a,b
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/* 
 * 计算两个整数的平均值(位于二者中间的整数值)
 *
 * 函数输入:
 *   两个整数a,b
 *
 * 函数返回:
 *   两个整数的平均值(结果向下取整)
 */
int divtwo(int a, int b) {
    return (a + b) / 2;
}

/*
 * 快速排序
 */
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
        swap(list[j], list[m]);
        QuickSort(list, m, j - 1);
        QuickSort(list, j + 1, n);
    }
}

/*
 * 归并
 */
void Merge(int list[], int m, int n) {
    int Arr[N];
    int mid = divtwo(m, n);
    int i = m, j = mid + 1, k = m;
    while(i < mid + 1 && j < n + 1) {
        if(list[i] > list[j]) Arr[k++] = list[j++];
        else Arr[k++] = list[i++];
    }
    while(i < mid + 1) Arr[k++] = list[i++];
    while(j < n + 1) Arr[k++] = list[j++];
    for(int i = m; i <= n; i++) list[i] = Arr[i];
}

/*
 * 归并排序
 */
void MergeSort(int list[], int m, int n) {
    if(m < n) {
        int mid = divtwo(m, n);
        MergeSort(list, m, mid);
        MergeSort(list, mid + 1, n);
        Merge(list, m, n);
    }
}

/*
 * 选择排序
 */
void SelectSort(int list[], int m, int n) {
    if(m < n) {
        int k = 0;
        for(int i = m; i < n; i++) {
            k = i;
            for(int j = i + 1; j <= n; j++) 
                if(list[k] > list[j]) k = j;
            if(k != i) swap(list[k], list[i]);
        }
    }
}

/*
 * 气泡排序
 */
void BubbleSort(int list[], int m, int n) {
    if(m < n) {
        for(int i = m; i <= n - 1; i++) {
            for(int j = m; j < n - i; j++) {
                if(list[j] > list[j+1]) swap(list[j], list[j+1]);
            }
        }
    }
}

/*
 * 插入排序
 */
void InsertSort(int list[], int m, int n) {
    if(m < n) {
        int key, j;
        for(int i = m + 1; i <= n; i++) {
            key = list[i];
            for(j = i - 1; j > -1 && key < list[j]; j--) {
                list[j+1] = list[j];
            }
            list[j+1] = key;
        }
    }
}
