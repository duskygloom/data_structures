CC 		= gcc
BUILD	= build
OBJECTS = $(BUILD)/tree.o $(BUILD)/bst.o
BINARY 	= bst

all: test

main: $(BUILD)/main.o $(OBJECTS) 
	$(CC) $^ -o $(BINARY) -g

test: $(BUILD)/test.o $(OBJECTS) 
	$(CC) $^ -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c

init:
	mkdir $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o
