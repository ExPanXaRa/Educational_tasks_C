#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void sort_2(int *a, int size);
void data_clone(int *a, int *b);
void output_result(int *a, int *b);
void swap(int *a, int *b);

int main() {
    int data[NMAX];
    int data_2[NMAX];
    if (input(data) != 0) {
        printf("n/a");
        return 1;
    } else {
        data_clone(data, data_2);
        sort(data);
        sort_2(data_2, NMAX);
        output_result(data, data_2);
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

void sort_2(int *a, int size) {
    int start = 0;
    int end = size - 1;
    int mid = a[size / 2];
    do {
        while (a[start] < mid) {
            start++;
        }
        while (a[end] > mid) {
            end--;
        }
        if (start <= end) {
            swap(&a[start], &a[end]);
            start++;
            end--;
        }
    } while (start <= end);

    if (end > 0) {
        sort_2(a, end + 1);
    }
    if (start < size) {
        sort_2(&a[start], size - start);
    }
}

void data_clone(int *a, int *b) {
    for (int *p = a; p - a < NMAX; p++) {
        b[p - a] = *p;
    }
}

void output_result(int *a, int *b) {
    for (int *p = a; p - a < NMAX; p++) {
        if (p - a != NMAX - 1) {
            printf("%d ", *p);
        } else {
            printf("%d\n", *p);
        }
    }
    for (int *k = b; k - b < NMAX; k++) {
        if (k - b != NMAX - 1) {
            printf("%d ", *k);
        } else {
            printf("%d", *k);
        }
    }
}