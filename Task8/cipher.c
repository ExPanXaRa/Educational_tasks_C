#include <stdio.h>
#include <stdlib.h>

void read_f(char *filename, int *flag_first);
void write(int *flag_first, char *filename);

int main() {
    int flag = 0;
    int flag_first = 0;
    while (flag != -1) {
        if (scanf("%d", &flag) == 1 && (flag == 1 || flag == 2)) {
            char filename[1000];
            if (flag == 1) {
                scanf("%999s", filename);
                read_f(filename, &flag_first);
                flag_first = 1;
            } else if (flag == 2) {
                write(&flag_first, filename);
            } else if (flag == 3) {
                write(&flag_first, filename);
            } else {
                printf("n/a\n");
            }
        } else {
            if (flag != -1) printf("n/a\n");
        }
        while (getchar() != '\n') {
        }
    }
    return 0;
}

void read_f(char *filename, int *flag_first) {
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        char buffer[1000];
        if ((fgets(buffer, 1000, fp)) == NULL) {
            printf("n/a\n");
        } else {
            printf("%s", buffer);
            while ((fgets(buffer, 1000, fp)) != NULL) {
                printf("%s", buffer);
            }
            printf("\n");
        }
        *flag_first = 1;
        fclose(fp);
    } else {
        printf("n/a\n");
    }
}

void write(int *flag_first, char *filename) {
    char message[1000];
    scanf("%999s", message);
    if (*flag_first != 1) {
        printf("n/a\n");
    } else {
        FILE *fp2 = fopen(filename, "a");
        if (fp2 != NULL) {
            fputs(message, fp2);
            fclose(fp2);
            read_f(filename, flag_first);
            *flag_first = 0;
        }
    }
}