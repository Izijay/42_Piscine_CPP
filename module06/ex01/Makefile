# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 12:10:31 by mdupuis           #+#    #+#              #
#    Updated: 2022/06/30 12:19:46 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	serialization

CXX				=	c++

#SRC_DIR			=	$(shell find srcs -type d)

OBJ_DIR			=	.obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

# Library -----------------------------------------------------------

SRCS			=	main.cpp

INC				=	./Data.hpp

OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

# Compilation flags -------------------------------------------------

CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

#IFLAGS			=	-I ./includes

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

$(OBJ_DIR)/%.o : %.cpp Data.hpp
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CPPFLAGS) -c $< -o $@
	@echo "$(_GREEN)DONE$(_WHITE)"

all:	$(NAME)

$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@rm -rf $(OBJ_DIR)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re:	fclean all

.PHONY: all bonus re clean flcean