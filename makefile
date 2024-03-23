CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = NSC.cpp
TARGET = nsc

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
