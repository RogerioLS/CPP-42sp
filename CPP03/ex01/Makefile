# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 00:57:01 by codespace         #+#    #+#              #
#    Updated: 2024/12/19 00:47:04 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= claptrap

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra
INCLUDES	= -I includes 

VPATH		= sources
FILES		= ClapTrap.cpp \
			ScavTrap.cpp   \
			main.cpp       \

OBJS		= $(FILES:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR		= objects

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all