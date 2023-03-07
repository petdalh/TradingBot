CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/trading_bot

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Download the data before building the C++ program
data/AAPL.txt:
	python3 src/download_data.py

# Import the data before building the C++ program
$(BUILD_DIR)/import_data.o: include/import_data.h

# Make sure the data is downloaded and imported before running the C++ program
$(TARGET): data/AAPL.txt $(BUILD_DIR)/import_data.o

clean:
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)

