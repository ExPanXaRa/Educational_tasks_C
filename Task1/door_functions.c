#include <math.h>
#include <stdio.h>

double first(double a);
double second(double a);
double third(double a);

int main() {
    const double pi = 3.14159265358979323846;
    double count_pi = pi * -1;
    double timed_pi = pi * 2 / 41;
    while (count_pi < pi) {
        if (isnan(second(count_pi))) {
            printf("%.7f | %.7f | - | %.7f\n", count_pi, first(count_pi), third(count_pi));
        } else {
            printf("%.7f | %.7f | %.7f | %.7f\n", count_pi, first(count_pi), second(count_pi),
                   third(count_pi));
        }
        count_pi += timed_pi;
    }
}

double first(double a) {
    double first = pow(1, 3) / (pow(1, 2) + pow(a, 2));
    return first;
}

double second(double a) {
    double second = sqrt((sqrt(pow(1, 4) + (4 * pow(a, 2) * pow(1, 2))) - pow(a, 2) - pow(1, 2)));
    return second;
}

double third(double a) {
    double third = 1 / pow(a, 2);
    return third;
}