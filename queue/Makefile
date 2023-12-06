CC		= gcc
BUILD	= build
OBJECTS = $(BUILD)/circular_queue.o
BINARY	= a.exe

all: main

main: $(OBJECTS) $(BUILD)/main.o
	$(CC) $^ -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

clean:
	rm $(BUILD)/*
