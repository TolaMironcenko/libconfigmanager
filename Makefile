CXX=g++
CXXFLAGS=-Wall -std=c++23
SOURCES=src/main.cpp src/ConfigManager.cpp
TARGET=bin/config_manager

SHAREDTARGET=lib/libconfigmanagercpp.so
SHAREDSOURCES=src/ConfigManager.cpp

default: all

all: build shared

build:
	@if [ ! -d bin ]; then \
		mkdir bin; \
	fi
	$(CXX) -o $(TARGET) $(SOURCES) $(CXXFLAGS)

shared:
	@if [ ! -d lib ]; then \
		mkdir lib; \
	fi
	$(CXX) -shared -fPIC -o $(SHAREDTARGET) $(SHAREDSOURCES) $(CXXFLAGS)

clean:
	rm -v $(TARGET)
	rm -v $(SHAREDTARGET)
	
install:
	install $(SHAREDTARGET) /usr/lib
	install src/lib/ConfigManager.hpp /usr/include
	install src/lib/json.hpp /usr/include

uninstall:
	@rm -v /usr/lib/libconfigmanagercpp.so
	@rm -v /usr/include/ConfigManager.hpp
	@rm -v /usr/include/json.hpp
