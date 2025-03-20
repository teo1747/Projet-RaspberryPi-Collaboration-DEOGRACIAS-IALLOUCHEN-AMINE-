CC = gcc
CFLAGS = -Wall -I./gpio -I./common
LDFLAGS =

SRCS =pmod_swt/pmod_swt.c gpio/gpio.c
OBJS = $(SRCS:.c=.o)
TARGET = pmodswt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
