# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g

# Define directories for include, source, and executable
INCLUDE_DIR = include
SRC_DIR = src
EXE_DIR = exe

# Define the target executable and source files
TARGET = $(EXE_DIR)/xy_bits
SRC_FILES = $(SRC_DIR)/xy_bits.c $(SRC_DIR)/my_bitwise.c

# Include the directory path for header files
INCLUDES = -I$(INCLUDE_DIR)

# Build the target executable from xy_bits.c and my_bitwise.c
all: $(TARGET)

# Link the object files and remove them after linking
$(TARGET): $(SRC_DIR)/xy_bits.o $(SRC_DIR)/my_bitwise.o
	@echo "Linking the program..."
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(SRC_DIR)/xy_bits.o $(SRC_DIR)/my_bitwise.o
	@rm -f $(SRC_DIR)/xy_bits.o $(SRC_DIR)/my_bitwise.o  # Remove object files after building

# Compile xy_bits.c into xy_bits.o
$(SRC_DIR)/xy_bits.o: $(SRC_DIR)/xy_bits.c
	@echo "Compiling xy_bits.c..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/xy_bits.c -o $(SRC_DIR)/xy_bits.o

# Compile my_bitwise.c into my_bitwise.o
$(SRC_DIR)/my_bitwise.o: $(SRC_DIR)/my_bitwise.c
	@echo "Compiling my_bitwise.c..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/my_bitwise.c -o $(SRC_DIR)/my_bitwise.o

# Clean up the compiled files
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
