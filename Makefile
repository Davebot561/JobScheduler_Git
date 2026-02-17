# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -g

# Source files
SRC = src/main.c src/job.c src/queue.c
OBJ = $(SRC:.c=.o)

# Default target
all: main

# Build the executable called 'main'
main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(OBJ) main
