#compiler
CC = gcc

#compiler flags 
CFLAGS = -lncurses -lmenu

#build target executable
TARGET = rpg

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c $(CFLAGS)

clean:
	$(RM) $(TARGET)