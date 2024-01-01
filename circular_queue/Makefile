CC		= gcc
ARGS	= -Wall -g
BUILD	= build
OBJECTS	= $(BUILD)/circular_queue.o
OBJECTS_LINKED = $(BUILD)/circular_queue_linked.o $(BUILD)/linked_list.o
BINARY	= circular_queue

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
