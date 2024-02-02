/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *check);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int *length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length, buffer[NMAX], sum, numbers[NMAX], check = 0;
    input(buffer, &length, &check);
    if (check != 0) {
        printf("n/a");
        return 1;
    } else {
        sum = sum_numbers(buffer, length);
        if (sum == 0) {
            printf("n/a");
            return 1;
        }
        length = find_numbers(buffer, &length, sum, numbers);
        output(numbers, length, sum);
    }
    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int *length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < *length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[j] = buffer[i];
                j++;
            }
        }
    }
    return j;
}

void output(int *buffer, int length, int sum) {
    printf("%d\n", sum);
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            printf("%d ", buffer[i]);
        } else {
            printf("%d", buffer[i]);
        }
    }
}

void input(int *buffer, int *length, int *check) {
    if (scanf("%d", &*length) == 1) {
        if (*length <= 0 || *length > NMAX) {
            *check = 1;
            return;
        }
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) {
                *check = 1;
            }
        }
    } else {
        *check = 1;
    }
}