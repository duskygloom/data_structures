CC 		= gcc
BUILD	= build
OBJECTS = $(BUILD)/tree.o $(BUILD)/bst.o $(BUILD)/main.o
BINARY 	= a.exe

all: $(BINARY)

$(BINARY): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(BINARY) -g

$(BUILD)/tree.o: ../tree.c
	$(CC) $^ -o $@ -c

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c

clean:
	rm *.o
