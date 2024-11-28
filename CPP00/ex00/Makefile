# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 00:15:52 by codespace         #+#    #+#              #
#    Updated: 2024/11/28 00:27:38 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC		= c++
CFLAGS	= -std=c++98 -Wall -Werror -Wextra

FILES	= megaphone.cpp

OBJ_DIR	= obj
OBJS	= $(FILES:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re