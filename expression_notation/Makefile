CC		= gcc
BUILD	= build
OBJECTS	= $(BUILD)/expressions.o $(BUILD)/stack.o $(BUILD)/string.o
BINARY	= postfix

all: test

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) -g

test: $(BUILD)/test.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) -g

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

init:
	mkdir $(BUILD)

clean:
	rm $(BUILD)/*

run:
	./$(BINARY)
