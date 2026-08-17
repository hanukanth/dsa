CC := clang
CFLAGS := -Wall -Wextra -std=c11
TARGET := app
SOURCES := main.c linked_list.c arrays.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) common.h linked_list.h
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(TARGET)
