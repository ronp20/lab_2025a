# Define the compiler and compiler flags
CC = gcc
CFLAGS = -std=c89 -Wall -Werror -ansi -pedantic -g

# Define directories for include, source, and executable
INCLUDE_DIR = include
SRC_DIR = src
EXE_DIR = exe

# Define the target executable and source files
TARGET = $(EXE_DIR)/letters
SRC_FILES = $(SRC_DIR)/letters.c $(SRC_DIR)/my_std.c

# Include the directory path for header files
INCLUDES = -I$(INCLUDE_DIR)

# Build the target executable from letters.c and my_std.c
all: $(TARGET)

# Link the object files and remove them after linking
$(TARGET): $(SRC_DIR)/letters.o $(SRC_DIR)/my_std.o
	@echo "Linking the program..."
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(SRC_DIR)/letters.o $(SRC_DIR)/my_std.o
	@rm -f $(SRC_DIR)/letters.o $(SRC_DIR)/my_std.o  # Remove object files after building

# Compile letters.c into letters.o
$(SRC_DIR)/letters.o: $(SRC_DIR)/letters.c
	@echo "Compiling letters.c..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/letters.c -o $(SRC_DIR)/letters.o

# Compile my_std.c into my_std.o
$(SRC_DIR)/my_std.o: $(SRC_DIR)/my_std.c
	@echo "Compiling my_std.c..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/my_std.c -o $(SRC_DIR)/my_std.o

# Clean up the compiled files
clean:
	@rm -f $(TARGET)
	@echo "Cleaned up!"
