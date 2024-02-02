#include <math.h>
#include <stdio.h>

double first(double a);
double second(double a);
double third(double a);

int main() {
  const double pi = 3.14159265358979323846;
  double count_pi = pi * -1;
  double count_pi_sec = count_pi;
  double timed_pi = pi * 2 / 41;
  double count_graf_i = (0.9941630 - 0.0919997) / 21;
  double i = 0.9941630;
  unsigned long long lol, kek1, kek2;
  int check = 41;
  while (i > 0.0919997) {
    while (count_pi < pi) {
      lol = first(count_pi_sec + (timed_pi * check)) * 100000000;
      kek1 = (i - count_graf_i) * 100000000;
      kek2 = (i + count_graf_i) * 100000000;
      if (lol > kek1 && lol < kek2) {
        printf("*");
      } else {
        printf(" ");
      }
      count_pi += timed_pi;
      check -= 1;
    }
    printf("\n");
    count_pi = pi * -1;
    i -= count_graf_i;
    check = 41;
  }

  check = 41;
  count_pi = pi * -1;
  double count_graf_k = (0.4996003 - 0.0761782) / 21;
  double k = 0.4996003;
  while (k > 0.0761782) {
    while (count_pi < pi) {
      lol = first(count_pi_sec + (timed_pi * check)) * 100000000;
      kek1 = (k - count_graf_k) * 100000000;
      kek2 = (k + count_graf_k) * 100000000;
      if (lol > kek1 && lol < kek2) {
        printf("*");
      } else {
        printf(" ");
      }
      count_pi += timed_pi;
      check -= 1;
    }
    printf("\n");
    count_pi = pi * -1;
    k -= count_graf_k;
    check = 41;
  }

  check = 41;
  count_pi = pi * -1;
  double count_graf_j = (170.3209097 - 0.1013212) / 21;
  double j = 170.3209097;
  while (j > 0.0919997) {
    while (count_pi < pi) {
      lol = first(count_pi_sec + (timed_pi * check)) * 100000000;
      kek1 = (j - count_graf_j) * 10000000;
      kek2 = (j + count_graf_j) * 10000000;
      if (lol > kek1 && lol < kek2) {
        printf("*");
      } else {
        printf(" ");
      }
      count_pi += timed_pi;
      check -= 1;
    }
    printf("\n");
    count_pi = pi * -1;
    j -= count_graf_j;
    check = 41;
  }
}

double first(double a) {
  double first = pow(1, 3) / (pow(1, 2) + pow(a, 2));
  return first;
}

double second(double a) {
  double second = sqrt(
      (sqrt(pow(1, 4) + (4 * pow(a, 2) * pow(1, 2))) - pow(a, 2) - pow(1, 2)));
  return second;
}

double third(double a) {
  double third = 1 / pow(a, 2);
  return third;
}