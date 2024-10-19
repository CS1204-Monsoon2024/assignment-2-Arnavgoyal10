
CXX = g++
CXXFLAGS = -std=c++17 -Wall


TARGET = main.out


SRCS = main.cpp HashTable.cpp


default: $(TARGET)


$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)


clean:
	rm -f $(TARGET)
