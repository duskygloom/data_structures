CC		= gcc
BUILD 	= build
SOURCES	= $(BUILD)/main.o $(BUILD)/heap.o
BINARY	= a.exe

all: $(BINARY)

$(BINARY): $(SOURCES)
	$(CC) $(SOURCES) -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c -g

clean:
	rm $(BUILD)/*.o
