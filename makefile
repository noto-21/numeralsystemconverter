# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Include directories
INC = -I$(INCLUDE_DIR)

# Target
TARGET = $(BUILD_DIR)/nsc

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Compile .cpp files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Clean
clean:
	@$(RM) -r $(BUILD_DIR)
