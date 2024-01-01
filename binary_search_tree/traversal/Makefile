CC 		= gcc
ARGS	= -Wall -g
BUILD	= build
OBJECTS = $(BUILD)/tree.o $(BUILD)/bst.o
BINARY 	= bst

all: test

main: $(BUILD)/main.o $(OBJECTS) 
	$(CC) $^ -o $(BINARY) $(ARGS)

test: $(BUILD)/test.o $(OBJECTS) 
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

init:
	mkdir $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o
