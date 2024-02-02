#include <stdio.h>

int mozg(int a);

int main() {
    int a;
    if ((scanf("%d", &a) == 1) && getchar() == '\n' && a > 0) {
        printf("%d", mozg(a));
        return 0;
    } else {
        printf("n/a");
        return -1;
    }
}

int mozg(int a) {
    if (a == 1 || a == 2) {
        return 1;
    } else {
        return mozg(a - 1) + mozg(a - 2);
    }
}