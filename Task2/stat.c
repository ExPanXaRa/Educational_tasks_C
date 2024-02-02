#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int *np = &n;
    if (input(data, np) != 0) {
        printf("n/a");
        return 1;
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", &*n) == 1) {
        if (*n <= 0 || *n >= NMAX) {
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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

int max(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f, %.6f", max_v, min_v, mean_v, variance_v);
}
