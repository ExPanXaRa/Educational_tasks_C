#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(double mean_v, double variance_v, int *a, int n);

int main() {
    int n, data[NMAX];
    int *np = &n;
    if (input(data, np) != 0) {
        printf("n/a");
        return 1;
    } else {
        output_result(mean(data, n), variance(data, n), data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", &*n) == 1) {
        if (*n <= 0 || *n > NMAX) {
            return 1;
        }
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                return 1;
            }
        }
        if (getchar() != '\n') {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

double mean(int *a, int n) {
    double mean = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    mean = sum / n;
    return mean;
}

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double variance = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - mean_v) * (a[i] - mean_v);
    }
    variance = sum / n;
    return variance;
}

void output_result(double mean_v, double variance_v, int *a, int n) {
    int output_result = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && a[i] != 0 && a[i] <= (mean_v + 3 * sqrt(variance_v))) {
            output_result = a[i];
        }
    }
    printf("%d", output_result);
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
