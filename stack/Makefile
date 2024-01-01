CC		= gcc
ARGS	= -Wall -g
BUILD	= build
OBJECTS	= $(BUILD)/stack.o
OBJECTS_LINKED = $(BUILD)/stack_linked.o $(BUILD)/linked_list.o
BINARY	= stack

all: main_linked

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

main_linked: $(BUILD)/main_linked.o $(OBJECTS_LINKED)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BINARY): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir $(BUILD)

clean:
	rm $(BUILD)/*

run:
	./$(BINARY)
