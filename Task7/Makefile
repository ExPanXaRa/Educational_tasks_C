CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET1 = ../build/Quest_1
TARGET2 = ../build/Quest_2

all: main

main: door_struct list_test

list_test: list.c list_test.c
	$(CC) $(CFLAGS) list.c list_test.c -o $(TARGET2)

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o $(TARGET1)

dmanager_module.o: dmanager_module.c	
	$(CC) $(CFLAGS) -c dmanager_module.c

clean:
	rm -rf *.o $(TARGET1) $(TARGET2)

rebuild: clean all