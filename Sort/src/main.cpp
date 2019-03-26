// 测试算法实现函数正确性
// Written by: Modnar.
// Edit Date: 2018.7.2

#include "sort.cpp"

const int N = 20;

void get_random_seq(std::vector<int> &ivec) {
    static std::default_random_engine e(time(nullptr));
    static std::uniform_int_distribution<int> dis(0, 100);
    ivec.clear();
    for (size_t i = 0; i < N; ++i)
        ivec.push_back(dis(e));
}

/*
 * 测试程序
 *
 * 对于每个排序函数，均为其生成一个随机数组，令每个函数对这个数组进行升序排序
 * 程序运行结(排序结果)输出到标准输出
 */
int main(int argc, char *argv[]) {
    srand((unsigned)time(nullptr));
    std::vector<int> ivec;
    get_random_seq(ivec);
    std::cout << "QuickSort:" << std::endl;
    quicksort(ivec, 0, ivec.size());
    for(auto x : ivec) std::cout << x << "  ";
    std::cout << std::endl << std::endl;

    get_random_seq(ivec);
    std::cout << "MergeSort:" << std::endl;
    mergesort(ivec, 0, ivec.size());
    for(auto x : ivec) std::cout << x << "  ";
    std::cout << std::endl << std::endl;

    get_random_seq(ivec);
    std::cout << "SelectSort:" << std::endl;
    selectsort(ivec, 0, ivec.size());
    for(auto x : ivec) std::cout << x << "  ";
    std::cout << std::endl << std::endl;

    get_random_seq(ivec);
    std::cout << "BubbleSort:" << std::endl;
    bubblesort(ivec, 0, ivec.size());
    for(auto x : ivec) std::cout << x << "  ";
    std::cout << std::endl << std::endl;

    get_random_seq(ivec);
    std::cout << "InsertSort:" << std::endl;
    insertsort(ivec, 0, ivec.size());
    for(auto x : ivec) std::cout << x << "  ";
    std::cout << std::endl << std::endl;

    return 0;
}
