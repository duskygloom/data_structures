CC		= gcc
ARGS	= -Wall -g
BUILD	= build
OBJECTS	= $(BUILD)/left_multistack.o
BINARY	= ./a.exe

all: $(BINARY)
	$(BINARY)

$(BINARY): main

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c $(ARGS)

clean:
	rm $(BUILD)/*.o
