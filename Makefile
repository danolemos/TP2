CC = gcc-11
CFLAGS = -Wall -Wextra -std=c11

TARGET = meu_programa
SOURCE_FILES = main.c queue.c queue.h

$(TARGET): $(SOURCE_FILES)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)
