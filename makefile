# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = main.out

# Source files
SRCS = main.cpp HashTable.cpp

# Default target to build the program
default: $(TARGET)

# Rule to create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up the build files
clean:
	rm -f $(TARGET)
