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
	@rm -f $(OBJ)  # Clean object file after linking

# Clean up
clean:
	@rm -f $(TARGET)
	@echo "Cleaned up!"

# Run tests
run-tests: $(TARGET)
	@echo "Running tests..."
	@$(TARGET) < tests/input/test1 > tests/output/test1
	@echo "Test 1 completed."
	@$(TARGET) < tests/input/test2 > tests/output/test2
	@echo "Test 2 completed."
	@$(TARGET) < tests/input/test3 > tests/output/test3
	@echo "Test 3 completed."
	@$(TARGET) < tests/input/test4 > tests/output/test4
	@echo "Test 4 completed."
