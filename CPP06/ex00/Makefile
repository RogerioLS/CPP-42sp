# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 15:31:45 by roglopes          #+#    #+#              #
#    Updated: 2025/03/16 13:23:22 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= converter

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra
INCLUDES	= -I includes 

VPATH		= sources
FILES		= ScalarConverter.cpp           \
			main.cpp                   \

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