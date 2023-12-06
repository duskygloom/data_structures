CC		= gcc
BUILD 	= build
BINARY	= a.exe
SOURCES	= $(BUILD)/hash_table.o $(BUILD)/movie.o $(BUILD)/linked_list.o

all: main

main: $(SOURCES) $(BUILD)/main.o
	$(CC) $^ -o $(BINARY) -g

$(BINARY): $(SOURCES)
	$(CC) $(SOURCES) -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

clean:
	rm $(BUILD)/*
