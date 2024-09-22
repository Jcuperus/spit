CXX := clang++
CXXFLAGS := --std=c++23
LDFLAGS := -lSDL2 -lSDL2_image -lSDL2_ttf

BUILD_DIR ?=./build
SRC_DIR ?= ./src
EXE ?= spit

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR) $(EXE)
