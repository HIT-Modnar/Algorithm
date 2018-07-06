#include "Header.h"

int main(int argc, char ** argv) {
    srand((unsigned)time(NULL));
    int list[N];
    for(int i = 0; i < N; i++) {
        list[i] = rand() % 100 + 1;
    }
    list[0] = 50;
    QuickSort(list, 0, N - 1);
    for(int i = 0; i < N; i++) std::cout << list[i] << "  ";
    std::cout << std::endl;
    printf("Search the index: %d\n", BinarySearch(list, 0, N - 1, 50));
    return 0;
}
