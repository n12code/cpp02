NAME = fixed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
I_FLAGS = -I$(INC_DIR)

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

FILES = main Fixed

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

HEADERS = Fixed.hpp
HEADERS := $(addprefix $(INC_DIR)/, $(HEADERS))


all: $(NAME)

$(NAME): $(OBJ)
	@echo "compiling the binary\n"
	$(CXX) $(CXXFLAGS) $(I_FLAGS) $(OBJ) -o $(NAME)
	@echo "\nprogram created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@echo "compiling the obj"
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(I_FLAGS) -c $< -o $@

clean:
	@echo "removing obj"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "removing the binary"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
