NAME = fixed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
I_FLAGS = -I$(INCS_DIR)

OBJS_DIR = objs
SRCS_DIR = srcs
INCS_DIR = includes

FILES = main Fixed

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .cpp, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))
DEPS := $(OBJS:.o=.d)

HEADERS = Fixed.hpp
HEADERS := $(addprefix $(INCS_DIR)/, $(HEADERS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\ncompiling the binary"
	$(CXX) $(CXXFLAGS) $(I_FLAGS) $(OBJS) -o $(NAME)
	@echo "\nprogram created"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@echo "\ncompiling the object"
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(I_FLAGS) -c $< -o $@

clean:
	@echo "\nremoving the objects"
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "\nremoving the binary"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)