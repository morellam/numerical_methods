#simple Makefile to run the .cpp code
CXX = c++
CXXFLAGS = -Wall -std=c++11 -o
VPATH = ./src2
SOURCES = simpson.cpp
TARGET = simpson 
TEXTFILES = ./pyplot/errors.txt

$(TARGET) : $(SOURCES)
	$(CXX) $(CXXFLAGS) $@ $^

.PHONY = clean

clean : 
	@rm -f $(TARGET) $(TEXTFILES)  

