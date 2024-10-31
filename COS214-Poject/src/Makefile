# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Source and object files
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

# Output executable
TARGET := bin/your_program

# Ensure the bin directory exists
$(TARGET): $(OBJECTS)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each .cpp file to .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
