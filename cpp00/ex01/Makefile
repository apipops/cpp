
#### NAME
NAME = phonebook

#### SOURCES
SRC += main.cpp
SRC += PhoneBook.cpp
SRC += Contact.cpp

#### OBJECTS
OBJ = $(SRC:.c=.o)

#### HEADERS
INCLUDE += PhoneBook.hpp
INCLUDE += Contact.hpp

#### COMPILATION
COMP = c++
FLAGS += -Wall -Wextra -Werror
FLAGS += -std=c++98

#### COLORS
BLUE = \033[1;94m
PURPLE = \033[1;95m
GREEN = \033[1;92m
YELLOW = \033[1;93m

#### RULES
all: $(NAME)

%.o: %.c
	@$(COMP) $(FLAGS) -I./$(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(YELLOW)------Compilation executed------\n\n"


clean:
	@/bin/rm -f $(OBJ)
	@printf "$(PURPLE)------Object files deleted-------\n\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

.PHONY : all clean fclean re

