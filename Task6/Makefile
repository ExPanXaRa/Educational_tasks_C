CC = gcc
CFLAGS = -Wall -Werror -Wextra
PEREMEN=s21_string.c s21_string_test.c
DT=-DQUEST
TARGET = ../build/Quest_
 
all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests:
	$(CC) $(DT)1 $(CFLAGS) $(PEREMEN) -o $(TARGET)1

strcmp_tests: 
	$(CC) $(DT)2 $(CFLAGS) $(PEREMEN) -o $(TARGET)2

strcpy_tests:
	$(CC) $(DT)3 $(CFLAGS) $(PEREMEN) -o $(TARGET)3

strcat_tests: 
	$(CC) $(DT)4 $(CFLAGS) $(PEREMEN) -o $(TARGET)4

strchr_tests: 
	$(CC) $(DT)5 $(CFLAGS) $(PEREMEN) -o $(TARGET)5

strstr_tests: 
	$(CC) $(DT)6 $(CFLAGS) $(PEREMEN) -o $(TARGET)6

strtok_tests:
	$(CC) $(DT)7 $(CFLAGS) $(PEREMEN) -o $(TARGET)7

clean: 
	rm -rf *.o *.a *.so all $(TARGET)1 $(TARGET)2 $(TARGET)3 $(TARGET)4 $(TARGET)5 $(TARGET)6 $(TARGET)7

rebuild: clean all