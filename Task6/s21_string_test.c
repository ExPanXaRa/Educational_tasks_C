#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef QUEST1
    s21_strlen_test();
#endif
#ifdef QUEST2
    s21_strcmp_test();
#endif
#ifdef QUEST3
    s21_strcpy_test();
#endif
#ifdef QUEST4
    s21_strcat_test();
#endif
#ifdef QUEST5
    s21_strchr_test();
#endif
#ifdef QUEST6
    s21_strstr_test();
#endif
#ifdef QUEST7
    s21_strtok_test();
#endif
}

void s21_strlen_test() {
    size_t rezult = s21_strlen("LokaLokaLoka");  // Подсчет количества символов
    printf("LokaLokaLoka %ld %s\n", rezult, (rezult == 12) ? "SUCCESS" : "FAIL");

    rezult = s21_strlen("\t213\t");
    printf("\\t213\\t %ld %s\n", rezult, (rezult == 5) ? "SUCCESS" : "FAIL");

    rezult = s21_strlen("");
    printf(" %ld %s", rezult, (rezult == 0) ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test() {
    int rezult = s21_strcmp("MikaMika", "MikaMika");  // Сравнение строк
    printf("MikaMika MikaMika %d %s\n", rezult, (rezult == 0) ? "SUCCESS" : "FAIL");

    rezult = s21_strcmp("MikaMika", " ");
    printf("MikaMika   %d %s\n", rezult, (rezult != 0) ? "SUCCESS" : "FAIL");

    rezult = s21_strcmp("MikaMika", "ikaMiko");
    printf("MikaMika ikaMiko %d %s", rezult, (rezult != 0) ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test() {
    char rezult[25];  // Копирование строк
    printf("Hello %s %s\n", s21_strcpy(rezult, "Hello"),
           (s21_strcmp(s21_strcpy(rezult, "Hello"), "Hello") == 0) ? "SUCCESS" : "FAIL");

    printf("12343 324 ss! %s %s\n", s21_strcpy(rezult, "12343 324 ss!"),
           (s21_strcmp(s21_strcpy(rezult, "12343 324 ss!"), "12343 324 ss!") == 0) ? "SUCCESS" : "FAIL");

    printf(" %s %s", s21_strcpy(rezult, ""),
           (s21_strcmp(s21_strcpy(rezult, ""), "") == 0) ? "SUCCESS" : "FAIL");
}

void s21_strcat_test() {
    char* str = (char*)calloc(100, 1);  // Объединение строк
    s21_strcat(str, "MikaMika");
    s21_strcat(str, "MikaMika");
    printf("MikaMika MikaMika %s %s\n", str, (s21_strcmp(str, "MikaMikaMikaMika") == 0) ? "SUCCESS" : "FAIL");

    char* str2 = (char*)calloc(100, 1);
    s21_strcat(str2, " ");
    s21_strcat(str2, "123\t");
    printf("  123\\t %s %s\n", str2, (s21_strcmp(str2, " 123\t") == 0) ? "SUCCESS" : "FAIL");

    char* str3 = (char*)calloc(100, 1);
    s21_strcat(str3, "12453246");
    s21_strcat(str3, "0-=0-=0-");
    printf("12453246 0-=0-=0- %s %s", str3, (s21_strcmp(str3, "124532460-=0-=0-") == 0) ? "SUCCESS" : "FAIL");

    free(str);
    free(str2);
    free(str3);
}

void s21_strchr_test() {
    char* rezult = s21_strchr("123465", '6');  // Поиск первого вхождения символа в строку
    printf("123465 6 %s %s\n", rezult, (s21_strcmp(rezult, "65") == 0) ? "SUCCESS" : "FAIL");

    rezult = s21_strchr("Hello W0rld", '0');
    printf("Hello W0rld 6 %s %s\n", rezult, (s21_strcmp(rezult, "0rld") == 0) ? "SUCCESS" : "FAIL");

    rezult = s21_strchr("Hell 6 yeah", '6');
    printf("Hell 6 yeah 6 %s %s", rezult, (s21_strcmp(rezult, "6 yeah") == 0) ? "SUCCESS" : "FAIL");
}

void s21_strstr_test() {
    const char* rezult = s21_strstr("MikaVika", "ikaV");  // Поиск первого вхождения строки А в строку В.
    printf("MikaVika ikaV %s %s\n", rezult, (s21_strcmp(rezult, "ikaVika") == 0) ? "SUCCESS" : "FAIL");

    rezult = s21_strstr("0123", "3");
    printf("0123 3 %s %s\n", rezult, (s21_strcmp(rezult, "3") == 0) ? "SUCCESS" : "FAIL");

    rezult = s21_strstr("asdhsdaH", "H");
    printf("asdhsdaH H %s %s", rezult, (s21_strcmp(rezult, "H") == 0) ? "SUCCESS" : "FAIL");
}

void s21_strtok_test() {
    printf("not yet");  // Разбиение строки на части по указанному разделителю.
}