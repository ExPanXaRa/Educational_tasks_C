#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double max_value = data[0];
    for (int i = 1; i < n; i++) {
        if (max_value < data[i]) max_value = data[i];
    }
    return max_value;
}

double min(double *data, int n) {
    double min_value = data[0];
    for (int i = 1; i < n; i++) {
        if (min_value > data[i]) min_value = data[i];
    }
    return min_value;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    double mean = sum / n * 1.0;
    return mean;
}

double variance(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + pow((data[i] - mean(data, n)), 2);
    }
    double variance = sum / n * 1.0;
    return variance;
}

double sort(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        for (int i = 0; i < n - 1; i++) {
            if (data[i] > data[i + 1]) {
                double swap_v = data[i];
                data[i] = data[i + 1];
                data[i + 1] = swap_v;
            }
        }
    }
    return 0;
}
