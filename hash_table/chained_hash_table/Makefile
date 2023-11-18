CC		= gcc
BUILD 	= build
BINARY	= a.exe
SOURCES	= $(BUILD)/main.o $(BUILD)/hash_table.o

all: $(BINARY)

$(BINARY): $(SOURCES)
	$(CC) $(SOURCES) -o $(BINARY) -g

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ -c

clean:
	rm $(BUILD)/*
