# Makefile for Raylib Level Editor


CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC = src/main.cpp src/cameraController.cpp src/tile.cpp src/blockPickerMenu.cpp src/const.cpp src/worldGrid.cpp src/worldGridController.cpp src/menuTile.cpp
HEADERS = include/const.hpp include/vec2.hpp include/cameraController.hpp include/tile.hpp include/worldGrid.hpp include/worldGridController.hpp include/blockPickerMenu.hpp include/menuTile.hpp
TARGET = build/levelEditor

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf build

.PHONY: all clean
