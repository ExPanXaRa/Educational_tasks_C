#ifndef S21_STRTING
#define S21_STRTING
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char* str);
int s21_strcmp(const char* str1, char* str2);
char* s21_strcpy(char* str1, const char* str2);
char* s21_strcat(char* str1, const char* str2);
char* s21_strchr(const char* str1, int c);
int compare(const char* X, const char* Y);
const char* s21_strstr(const char* str1, const char* str2);
size_t s21_strtok(const char* str);

#endif