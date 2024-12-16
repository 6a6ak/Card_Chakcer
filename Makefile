# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = main

# Build target
all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up build artifacts
clean:
	rm -f *.o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
