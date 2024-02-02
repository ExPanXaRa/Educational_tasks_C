CC=gcc
FLAGS=-Wall -Werror -Wextra
TARGET=../build/cipher

all: cipher

cipher: cipher.c
	$(CC) $(FLAGS) cipher.c -o $(TARGET)

clean:
	rm -rf $(TARGET)
	
rebuild: clean all