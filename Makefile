# ****************************** Colors & Styles *******************************
NC := \033[m
RED := \033[0;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[0;34m
PURPLE := \033[1;35m
CYAN := \033[1;36m

ITALIC := \033[1;3m
UNDERLINE := \033[1;4m

# ******************************** Directories *********************************
TEST_DIR := tests
TEMPLATES_DIR := templates
INC_DIR := includes
OBJ_DIR := tmp

# ****************************** Compiler Options ******************************
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD
INC_FLAGS := -I $(TEMPLATES_DIR) -I $(INC_DIR) -I $(TEST_DIR)/templates

# ********************************* Main Files *********************************
FT_NAME := ft_containers
STD_NAME := std_containers

FT_TESTS := $(TEST_DIR)/ft_containers.cpp
STD_TESTS := $(TEST_DIR)/std_containers.cpp

FT_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(FT_TESTS))
STD_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(STD_TESTS))

# ****************************** Make Arguments ********************************
ifdef debug
CXXFLAGS += -g
else
CXXFLAGS += -g -fsanitize=address
endif

# ******************************* Main Targets *********************************
all: $(STD_NAME) $(FT_NAME)

$(STD_NAME): $(STD_OBJS)
	echo "$(BLUE)Linking $(ITALIC)$(UNDERLINE)$(PURPLE)$@$(NC)"
	$(CXX) $(CXXFLAGS) $^ -o $@

$(FT_NAME): $(FT_OBJS)
	echo "$(BLUE)Linking $(ITALIC)$(UNDERLINE)$(PURPLE)$@$(NC)"
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	echo "$(GREEN)Compiling $(ITALIC)$(UNDERLINE)$(YELLOW)$(shell basename $<)$(NC)"
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

# ****************************** Global Targets ********************************
clean:
	echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(YELLOW)Object files$(NC)"
	rm -rf $(OBJ_DIR)

fclean: clean
	echo "$(RED)Removing$(NC) $(ITALIC)$(UNDERLINE)Debug symbols$(NC)"
	rm -rf *.dSYM
	echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(PURPLE)$(FT_NAME)$(NC)"
	$(RM) $(FT_NAME)
	echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(PURPLE)$(STD_NAME)$(NC)"
	$(RM) $(STD_NAME)

re: fclean all

.SILENT: $(FT_NAME) $(STD_NAME) $(FT_OBJS) $(STD_OBJS) $(OBJ_DIR) $(OBJS) \
	clean fclean
.PHONY: all clean fclean re

# ******************************** Dependencies ********************************
-include $(patsubst %.o, %.d, $(FT_OBJS))
-include $(patsubst %.o, %.d, $(STD_OBJS))
