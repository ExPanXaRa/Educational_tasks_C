#include <stdio.h>
#define NMAX 10

int input(int *data, int *length, int *shift_v);
void shift(int *data, int *data2, int length, int shift_v);
void output_result(int *data2, int length);

int main() {
    int data[NMAX], data2[NMAX], length, shift_v;
    if (input(data, &length, &shift_v) != 0) {
        printf("n/a");
        return 1;
    } else {
        shift(data, data2, length, shift_v);
        output_result(data2, length);
    }
    return 0;
}

int input(int *data, int *length, int *shift_v) {
    if (scanf("%d", length) != 1) {
        return 1;
    }
    if (*length <= 0 || *length > NMAX) {
        return 1;
    }
    for (int *p = data; p - data < *length; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    if (scanf("%d", shift_v) != 1) {
        return 1;
    }
    return 0;
}

void shift(int *data, int *data2, int length, int shift_v) {
    if (shift_v >= 0) {
        if (shift_v > length) {
            shift_v = shift_v % length;
        }
        for (int i = 0; i < length; i++) {
            if (i + shift_v < length) {
                data2[i] = data[i + shift_v];
            } else {
                data2[i] = data[i + shift_v - length];
            }
        }
    } else {
        if (shift_v * -1 > length) {
            shift_v = shift_v % length;
        }
        for (int i = 0; i < length; i++) {
            if (i + shift_v >= 0) {
                data2[i] = data[i + shift_v];
            } else {
                data2[i] = data[i + shift_v + length];
            }
        }
    }
}

void output_result(int *data2, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            printf("%d ", data2[i]);
        } else {
            printf("%d", data2[i]);
        }
    }
}