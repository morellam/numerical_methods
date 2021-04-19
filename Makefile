#simple Makefile to run the .cpp code
CC = c++
CFLAGS = -Wall -std=c++11 -o
SOURCES = src2/simpson.cpp
OBJECTS = $(SOURCES:.c=.o)
TARGET = simpson

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $@ $^

.PHONY = clean

clean : 
	@rm -f $(TARGET) $(OBJECTS) core

