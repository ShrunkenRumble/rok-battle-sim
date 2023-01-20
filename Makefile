INC_DIR 			:= include
SRC_DIR 			:= src
OBJ_DIR 			:= build
BIN_DIR 			:= bin

SIM	:= $(BIN_DIR)/sim
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXXPPFLAGS	:= -I$(INC_DIR) -MMD -MP
CXXFLAGS 	:= -std=c++20 -Wall
CXX			:= g++
LDLIBS		:= -lm

.PHONY: all clean

all: $(SIM)

$(SIM): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR): 
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
	
-include $(OBJ:.o=.d)