I_DIR := include
S_DIR := src
O_DIR := obj
B_DIR := bin
L_DIR := lib

SIM	:= $(B_DIR)/sim
SRC := $(wildcard $(S_DIR)/*.cpp)
OBJ := $(SRC:$(S_DIR)/%.cpp=$(O_DIR)/%.o)

CXXPPFLAGS	:= -I$(I_DIR) -MMD -MP
CXXFLAGS 	:= -std=c++11 -Wall
CXX			:= g++
LDFLAGS		:= -L$(L_DIR)
LDLIBS		:= -lm

.PHONY: all clean

all: $(SIM)

$(SIM): $(OBJ) | $(B_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(O_DIR)/%.o: $(S_DIR)/%.cpp | $(O_DIR)
	$(CXX) $(CXXPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(B_DIR) $(O_DIR): 
	mkdir -p $@

clean:
	@$(RM) -rv $(B_DIR) $(O_DIR)
	
-include $(OBJ:.o=.d)