CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= a.exe
SOURCES	= $(BUILD)/tree.o

all: main

main: $(BUILD)/main.o $(SOURCES)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ $(ARGS) -c

init:
	mkdir $(BUILD)

clean:
	rm $(BUILD)/*
	