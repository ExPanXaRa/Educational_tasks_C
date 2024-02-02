#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char* str) {
    size_t length = 0;
    for (; *(str + length); length++)
        ;
    return length;
}

int s21_strcmp(const char* str1, char* str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    return *str1 - *str2;
}

char* s21_strcpy(char* str1, const char* str2) {
    if (str1 == NULL) {
        return NULL;
    }
    char* ptr = str1;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return ptr;
}

char* s21_strcat(char* str1, const char* str2) {
    char* ptr = str1 + s21_strlen(str1);
    while (*str2 != '\0') {
        *ptr++ = *str2++;
    }
    *ptr = '\0';
    return str1;
}

char* s21_strchr(const char* str1, int c) {
    int i = 0;
    while (str1[i] && str1[i] != c) ++i;
    return c == str1[i] ? (char*)str1 + i : NULL;
}

int compare(const char* X, const char* Y) {
    while (*X && *Y) {
        if (*X != *Y) {
            return 0;
        }

        X++;
        Y++;
    }

    return (*Y == '\0');
}

const char* s21_strstr(const char* str1, const char* str2) {
    while (*str1 != '\0') {
        if ((*str1 == *str2) && compare(str1, str2)) {
            return str1;
        }
        str1++;
    }

    return NULL;
}

size_t s21_strtok(const char* str) {
    size_t length = 0;
    for (; *(str + length); length++)
        ;
    return length;
}