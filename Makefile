# Define the C compiler. 'make' has a smart default, but being explicit is good.
CC = gcc

# Define compiler flags. -Wall enables all warnings, which is good practice.
CFLAGS = -Wall -O3 -s

BUILD_DIR = build

# Define the source files for your game.
SOURCES = ./main.c 

# Define the name of the final executable.
TARGET = ${BUILD_DIR}/ticTacToe

# This is the main build rule. It's called when you run 'make game'.
# It tells make to build the TARGET from the SOURCES.
game: $(SOURCES)
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# A rule to clean up compiled files.
clean:
	rm -rf $(BUILD_DIR)
