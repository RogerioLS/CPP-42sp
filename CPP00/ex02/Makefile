# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 00:57:01 by codespace         #+#    #+#              #
#    Updated: 2024/11/30 17:26:37 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= account

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra
INCLUDES	= -I includes 

VPATH		= sources
FILES		= Account.cpp \
			tests.cpp \

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