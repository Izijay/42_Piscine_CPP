# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 12:10:31 by mdupuis           #+#    #+#              #
#    Updated: 2022/06/14 15:12:22 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	harlFilter

CXX				=	c++

CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

OBJ_DIR			=	.obj

OBJ				=	${SRCS:%.cpp=${OBJ_DIR}/%.o}

SRCS			=	./Harl.cpp \
					./main.cpp

INC				=	./Harl.hpp \

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

$(OBJ_DIR)/%.o : %.cpp $(INC) 
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