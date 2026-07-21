#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

    int L, R, c, d;
    int e = 0;

    scanf("%d %d", &L, &R);
    for (c = L;c <= R;c++) {
        int num = c;
        while (num) {
            d = num % 10;
            num /= 10;
            if (d == 2) {
                e++;
            }
        }
    }
    printf("%d", e);
    return 0;
}