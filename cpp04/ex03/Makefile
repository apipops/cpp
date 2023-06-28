
#### NAME
NAME		= interface

#### SOURCES
SRCS 		+= main.cpp
SRCS 		+= AMateria.cpp
SRCS 		+= Cure.cpp
SRCS 		+= Ice.cpp
SRCS 		+= Character.cpp
SRCS 		+= MateriaSource.cpp

#### OBJECTS
PATH_OBJS	= objs/
OBJS		= $(patsubst %.cpp, $(PATH_OBJS)/%.o, $(SRCS))

#### HEADERS
INCLUDES	+= AMateria.hpp
INCLUDES	+= Cure.hpp
INCLUDES	+= Ice.hpp
INCLUDES	+= Character.hpp
INCLUDES	+= ICharacter.hpp
INCLUDES	+= MateriaSource.hpp
INCLUDES	+= IMateriaSource.hpp

#### COMPILATION
COMP = c++
FLAGS += -Wall -Wextra -Werror
FLAGS += -std=c++98
MAKEFLAGS += --no-print-directory

#### COLORS
BLUE = \033[1;94m
PURPLE = \033[1;95m
GREEN = \033[1;92m
YELLOW = \033[1;93m

#### RULES
all: $(NAME)


$(NAME): $(OBJS) $(INCLUDES) Makefile
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(YELLOW)------Compilation executed------\n\n"

$(OBJS): $(PATH_OBJS)/%.o: %.cpp $(INCLUDES)
	@mkdir -p $(PATH_OBJS)
	@$(COMP) $(FLAGS) -c $< -o $@ -I./includes

clean:
	@$(RM) -R $(PATH_OBJS)
	@printf "$(PURPLE)------Object files deleted-------\n\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

.PHONY : all clean fclean re

