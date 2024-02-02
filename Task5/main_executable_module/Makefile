CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET1 = ../../build/Quest_3

TARGET2 = ../../build/Quest_5
TARGET3 = ../../build/Quest_6
LFLAGS = -shared -fpic
EFLAGS = -L. -ldata_process 

all: main build_with_static build_with_dynamic

main: data_io.o data_stat.o data_process.o decision.o main_executable_module.o
	$(CC) $(CFLAGS) data_io.o data_stat.o data_process.o decision.o main_executable_module.o -o $(TARGET1)

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c


data_stat.a: data_stat.o
	ar rcs libdata_stat.a data_stat.o
	ranlib libdata_stat.a

build_with_static: data_io.o data_process.o decision.o main_executable_module.o data_stat.a
	$(CC) $(CFLAGS) -o $(TARGET2) data_io.o data_process.o decision.o main_executable_module.o -ldata_stat -L. 


data_process.so: ../data_module/data_process.c data_stat.o
	$(CC) $(CFLAGS) $(LFLAGS) -o libdata_process.so ../data_module/data_process.c data_stat.o -Wl,-rpath,.

build_with_dynamic: data_io.o data_stat.o data_process.so decision.o main_executable_module.o
	$(CC) $(CFLAGS) data_io.o data_stat.o decision.o main_executable_module.o $(EFLAGS) -o $(TARGET3) -Wl,-rpath,.

clean: 
	rm -rf *.o *.a *.so main

rebuild: clean all