# Define the compiler and compiler flags
CC = gcc
CFLAGS = -std=c89 -Wall -Werror -ansi -pedantic -g  # Added -g for debugging

# Define the target executable
TARGET = letters

# Build the target executable from letters.c
all: $(TARGET)

# Link the object file and remove it after linking
$(TARGET): letters.o
	@echo "Linking the program..."
	@$(CC) $(CFLAGS) -o $(TARGET) letters.o
	@rm -f letters.o  # Remove the object file after building the executable

# Compile letters.c into letters.o
letters.o: letters.c
	@echo "Compiling letters.c..."
	@$(CC) $(CFLAGS) -c letters.c

# Clean up the compiled files
clean:
	@rm -f $(TARGET)
	@echo "Cleaned up!"
