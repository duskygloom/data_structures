CC		= gcc
BUILD	= build
OBJECTS	= $(BUILD)/hashtable.o
BINARY	= a.exe

all: main

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) -g

test: $(BUILD)/test.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

clean:
	rm $(BUILD)/*.o
