#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output_result(int *a);
void swap(int *a, int *b);

int main() {
    int data[NMAX];
    if (input(data) != 0) {
        printf("n/a");
        return 1;
    } else {
        sort(data);
        output_result(data);
    }
    return 0;
}

int input(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    return 0;
}

void sort(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        for (int *k = a; k - a < NMAX; k++) {
            if (*k > *(k + 1)) {
                swap(k, k + 1);
            }
        }
    }
}

void swap(int *a, int *b) {
    int swap_v = *a;
    *a = *b;
    *b = swap_v;
}

void output_result(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        if (p - a != NMAX - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}