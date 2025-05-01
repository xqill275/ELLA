# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -IInclude

# Directories
SRC_DIR := src/ELLA
BUILD_DIR := build
INCLUDE_DIR := Include/ELLA

# Output
TARGET := $(BUILD_DIR)/ella

# Find all .cpp files in SRC_DIR
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $@

# Compile each .cpp file into .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Make sure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean
