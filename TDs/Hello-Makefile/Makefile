CC = gcc
CFLAGS = -Wall -Wextra
TARGET = hello

all: $(TARGET)

$(TARGET): hello.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) hello.o main.o

hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c

main.o: main.c hello.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET)

