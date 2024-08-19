CXX=g++
CXXFLAGS=-Wall -std=c++23
SOURCES=src/main.cpp
TARGET=bin/config_manager

default: all

all: build

build:
	@if [ ! -d bin ]; then \
		mkdir bin; \
	fi
	$(CXX) -o $(TARGET) $(SOURCES) $(CXXFLAGS)

clean:
	rm -v $(TARGET)
	