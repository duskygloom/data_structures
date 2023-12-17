CC		= gcc
ARGS	= -g -Wall
BUILD	= build
OBJECTS	= $(BUILD)/hashtable.o $(BUILD)/table_item.o
BINARY	= a.exe

all: main

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

test: $(BUILD)/test.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

clean:
	rm $(BUILD)/*.o
