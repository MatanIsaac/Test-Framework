CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
TARGET = test

# Find all .c files in the directory
SRC = $(wildcard *.c)

# Generate object files for each .c file
OBJ = $(SRC:.c=.o)

# Find all .h files (for dependency tracking, but not directly compiled)
HEADERS = $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)
