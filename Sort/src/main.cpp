// 测试算法实现函数正确性
// Written by: Modnar.
// Edit Date: 2018.7.2
#include "Header.h"

/*
 * 测试程序
 *
 * 对于每个排序函数，均为其生成一个随机数组，令每个函数对这个数组进行升序排序
 * 程序运行结(排序结果)输出到标准输出
 */
int main(int argc, char **argv) {
    srand((unsigned)time(NULL));
    int list[N];
    for(int i = 0; i < N; i++) list[i] = rand() % 100 + 1;
    std::cout << "QuickSort:" << std::endl;
    QuickSort(list, 0, N - 1);
    for(int i = 0; i < N; i++) std::cout << list[i] << "  ";
    std::cout << std::endl << std::endl;

    for(int i = 0; i < N; i++) list[i] = rand() % 100 + 1;
    std::cout << "MergeSort:" << std::endl;
    MergeSort(list, 0, N - 1);
    for(int i = 0; i < N; i++) std::cout << list[i] << "  ";
    std::cout << std::endl << std::endl;

    for(int i = 0; i < N; i++) list[i] = rand() % 100 + 1;
    std::cout << "SelectSort:" << std::endl;
    SelectSort(list, 0, N - 1);
    for(int i = 0; i < N; i++) std::cout << list[i] << "  ";
    std::cout << std::endl << std::endl;

    for(int i = 0; i < N; i++) list[i] = rand() % 100 + 1;
    std::cout << "BubbleSort:" << std::endl;
    BubbleSort(list, 0, N - 1);
    for(int i = 0; i < N; i++) std::cout << list[i] << "  ";
    std::cout << std::endl << std::endl;

    for(int i = 0; i < N; i++) list[i] = rand() % 100 + 1;
    std::cout << "InsertSort:" << std::endl;
    InsertSort(list, 0, N - 1);
    for(int i = 0; i < N; i++) std::cout << list[i] << "  ";
    std::cout << std::endl << std::endl;

    return 0;
}
