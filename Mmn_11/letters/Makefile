# Compiler and flags
CC = gcc
CFLAGS = -std=c89 -Wall -Werror -ansi -pedantic -g -D_POSIX_C_SOURCE=1

# Directories and files
SRC = src/letters.c
TARGET = exe/letters

# Default target
all: $(TARGET)

# Compile and link
$(TARGET): $(SRC)
	@echo "Compiling and linking $(SRC)..."
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up
clean:
	@rm -f $(TARGET)
	@echo "Cleaned up!"

.PHONY: all clean