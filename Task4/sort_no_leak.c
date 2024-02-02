#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *length);
void sort(int *a, int length);
void output_result(int *a, int length);
void swap(int *a, int *b);

int main() {
    int length = 0;
    int *data2 = (int *)malloc(length * sizeof(int));
    if (input(data2, &length) != 0) {
        printf("n/a");
        return 1;
    } else {
        sort(data2, length);
        output_result(data2, length);
    }
    free(data2);
    return 0;
}

int input(int *a, int *length) {
    if (scanf("%d", length) == 1) {
        if (*length <= 0) {
            return 1;
        }
        for (int *p = a; p - a < *length; p++) {
            if (scanf("%d", p) != 1) {
                return 1;
            }
        }
    } else {
        return 1;
    }
    return 0;
}

void sort(int *a, int length) {
    for (int *p = a; p - a < length; p++) {
        for (int i = 0; i < length - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int swap_v = *a;
    *a = *b;
    *b = swap_v;
}

void output_result(int *a, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}