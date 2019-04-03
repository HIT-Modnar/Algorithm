#include <iostream>

void cal_next(char *str, int *next, int len) {
    next[0] = -1;
    int k = -1;
    for (int q = 1; q < len; q++) {
        while (k > -1 && str[k+1] != str[q]) {
            k = next[k];
        }
        if (str[k+1] == str[q]) {
            k++;
        }
        next[q] = k;
    }
}

void KMP(char *str, int slen, char *ptr, int len) {
    int *next = new int[len];
    cal_next(ptr, next, len);
    int k = -1;
//    for(int i = 0; i < len; i++) {
//        std::cout << next[i] << " ";
//    }
//    std::cout << std::endl;
    for (int i = 0; i < slen; i++) {
        while (k > -1 && ptr[k+1] != str[i]) 
            k = next[k];
        if (ptr[k+1] == str[i])
            k++;
        if (k == len - 1) {
            std::cout << "在位置" << i-len+1 << std::endl;
            k = -1;//重新初始化，寻找下一个
            i = i - len + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            //return i - len + 1;
        }
    }
    //return -1;
}

int main() {
    char str[] = "bacbababadababacambabacaddababacasdsd";
    char ptr[] = "ababaca";
    //printf("%d\n", KMP(str, 36, ptr, 7));
    KMP(str, 36, ptr, 7);
    return 0;
}
