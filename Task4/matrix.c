#include <stdio.h>
#include <stdlib.h>
#define NMAX 10000

int **input(int **a, int *b, int *lengthA, int *lengthB, int *sposob);
void output(int **a, int *lengthA, int *lengthB, int *b, int *sposob);
int stat(int *a, int *lengthA, int *lengthB);
void din1(int ***a, int *lengthA, int *lengthB);

int main() {
    int matr_stat[NMAX];
    int lengthA = 0, lengthB = 0;
    int **matr_dyn = NULL;
    int sposob = 0;
    matr_dyn = input(matr_dyn, matr_stat, &lengthA, &lengthB, &sposob);
    output(matr_dyn, &lengthA, &lengthB, matr_stat, &sposob);
    for (int i = 0; i < lengthA; i++) {
        free(matr_dyn[i]);
    }
    free(matr_dyn);
    return 0;
}

int **input(int **a, int *b, int *lengthA, int *lengthB, int *sposob) {
    scanf("%d %d %d", sposob, lengthA, lengthB);
    if (*sposob == 1) {
        stat(b, lengthA, lengthB);
    } else if (*sposob == 2) {
        din1(&a, lengthA, lengthB);
    }
    return a;
}

void output(int **a, int *lengthA, int *lengthB, int *b, int *sposob) {
    if (*sposob != 1) {
        for (int i = 0; i < *lengthA; i++) {
            for (int j = 0; j < *lengthB; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = 1; i <= *lengthA * *lengthB; i++) {
            if (i != *lengthA * *lengthB) {
                if (i % *lengthB == 0) {
                    printf("%d\n", b[i - 1]);
                } else {
                    printf("%d ", b[i - 1]);
                }
            } else {
                printf("%d", b[i - 1]);
            }
        }
    }
}

int stat(int *a, int *lengthA, int *lengthB) {
    for (int *p = a; p - a < *lengthA * *lengthB; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    return 0;
}

void din1(int ***a, int *lengthA, int *lengthB) {
    *a = (int **)malloc(*lengthA * sizeof(int *));
    for (int i = 0; i < *lengthA; i++) (*a)[i] = (int *)malloc(*lengthB * sizeof(int));
    for (int i = 0; i < *lengthA; i++) {
        for (int j = 0; j < *lengthB; j++) {
            scanf("%d", &(*a)[i][j]);
        }
    }
}
