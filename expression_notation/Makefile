CC		= gcc
BUILD	= build
OBJECTS	= $(BUILD)/expressions.o $(BUILD)/stack.o $(BUILD)/string.o
BINARY	= a.exe

all: test

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) -g

test: $(BUILD)/test.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) -g

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

clean:
	rm $(BUILD)/*
