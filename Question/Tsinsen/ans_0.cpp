#include <iostream>
#include <stdlib.h>
// A1000.
int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a + b << std::endl;
    return 0;
}

// A1001.
int main() {
    char ans[7] = "000000";
    for (int i = 0; i < 64; i++) {
        std::cout << ans << std::endl;
        for (int j = 5; j >= 0; j--) {
            if (ans[j] == '1') {
                ans[j] = '0';
                continue;
            } else {
                ans[j] = '1';
                break;
            }
        }
    }
    return 0;
}

// A1002.
int main() {
    char ans[7] = "000000";
    int flag = 0;
    for (int i = 0; i < 64; i++) {
        for (int j = 5; j >= 0; j--) {
            if (ans[j] == '1') {
                ans[j] = '0';
                flag--;
                continue;
            } else {
                ans[j] = '1';
                flag++;
                break;
            }
        }
        if (flag % 2 != 0) {
            std::cout << ans << std::endl;
        }
    }
    return 0;
}

// A1003.
int main() {
    int width = 18, height = 25;
    char ch[26];
    for (int i = 0; i < 26; i++) {
        ch[i] = 'A' + i;
    }
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if (j >= i) 
                std::cout << ch[j-i];
            else
                std::cout << ch[i-j];
        }
        std::cout << std::endl;
    }
    return 0;
}

// A1004.
int main() {
    int width = 0, height = 0;
    std::cin >> height >> width;
    char ch[26];
    for (int i = 0; i < 26; i++) {
        ch[i] = 'A' + i;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(j >= i) 
                std::cout << ch[j-i];
            else
                std::cout << ch[i-j];
        }
        std::cout << std::endl;
    }
    return 0;
}

// A1005.
int main() {
    for (int i = 100; i <= 999; i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        if (i == a * a * a + b * b * b + c * c * c) 
            std::cout << i << std::endl;
    }
    return 0;
}

// A1006.
int main() {
    for (int i = 10; i <= 99; i++) {
        std::cout << i << i % 10 << i / 10 << std::endl;
    }
    return 0;
}

// A1007.
int main() {
    int fiveBits[1000];
    int sixBits[1000];
    int fiveIndex = 0, sixIndex = 0;
    for (int i = 100; i <= 999; i++) {
         fiveBits[fiveIndex++] = i * 100 + (i / 10 % 10) * 10 + i / 100;
         sixBits[sixIndex++] = i * 1000 + (i % 10) * 100 + (i / 10 % 10) * 10 + i / 100;
    }
    int n = 0;
    std::cin >> n;
    int tempN = n;
    for (int i = 0; i < fiveIndex; i++) {
        tempN = n - fiveBits[i] / 100 % 10;
        if (tempN % 2 == 1) 
            continue;
        tempN = tempN / 2;
        if (tempN == fiveBits[i] / 10 % 10 + fiveBits[i] % 10)
            std::cout << fiveBits[i] << std::endl;
    }
    if (n % 2 == 0) {
        tempN = n / 2;
        for (int i = 0; i < sixIndex; i++) {
            if (sixBits[i] / 100 % 10 + sixBits[i] / 10 % 10 + sixBits[i] % 10 == tempN) 
                std::cout << sixBits[i] << std::endl;
        }
    }
    return 0;
}

// A1008.
int main() {
    int dig[10000];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dig[i];
    }
    int max = dig[0], min = dig[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (max < dig[i]) max = dig[i];
        if (min > dig[i]) min = dig[i];
        sum += dig[i];
    }
    std::cout << max << std::endl << min << std::endl << sum << std::endl;
    return 0;
}

// A1009.
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int list[], int m, int n) {
    if (m < n) {
        int i = m+1, j = n;
        int mid = (m + n) / 2;
        int key = list[mid];
        swap(list[mid], list[m]);
        while (i <= j) {
            while (i <= n && list[i] <= key) i++;
            while (j >= m && list[j] > key) j--;
            if (i < j) {
                swap(list[i], list[j]);
            }
        }
        swap(list[j], list[m]);
        quicksort(list, m, j-1);
        quicksort(list, j+1, n);
    }
}

int main() {
    int dig[100];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dig[i];
    }
    int sum = 0;
    quicksort(dig, 0, n-1);
    for (int i = 0; i < n; i++) {
        sum += dig[i] * dig[i];
    }
    std::cout << dig[n-2] << std::endl << dig[1] << std::endl << sum << std::endl;
    return 0;
}

