
#### NAME
NAME		= bureaucrat

#### SOURCES
SRCS 		+= main.cpp
SRCS 		+= Bureaucrat.cpp
SRCS 		+= AForm.cpp
SRCS 		+= ShrubberyCreationForm.cpp
SRCS 		+= RobotomyRequestForm.cpp
SRCS 		+= PresidentialPardonForm.cpp

#### OBJECTS
PATH_OBJS	= objs/
OBJS		= $(patsubst %.cpp, $(PATH_OBJS)/%.o, $(SRCS))

#### HEADERS
INCLUDES	+= Bureaucrat.hpp
INCLUDES	+= AForm.hpp
INCLUDES	+= RobotomyRequestForm.hpp
INCLUDES	+= PresidentialPardonForm.hpp

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
	@$(RM) *_shruberry
	@$(RM) $(NAME)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

.PHONY : all clean fclean re

