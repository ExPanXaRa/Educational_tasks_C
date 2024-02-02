#include <stdio.h>

int mozgA(int a, int b);
int mozgB(int a, int b);
int max_chislo(int a);

int main() {
    int a;
    if (scanf("%d", &a) == 1 && getchar() == '\n' && a != 1 && a != 0) {
        if (a < 0) {
            a *= -1;
        }
        printf("%d", max_chislo(a));
        return 0;
    } else {
        printf("n/a");
        return -1;
    }
}

int mozgA(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

int mozgB(int a, int b) {
    int count;
    while (a >= b) {
        a -= b;
        count++;
    }
    return count;
}

int max_chislo(int a) {
    int rezult = 2;
    while (a > 1) {
        if (mozgA(a, rezult) == 0) {
            a = mozgB(a, rezult);
        } else {
            rezult++;
        }
    }
    return rezult;
}