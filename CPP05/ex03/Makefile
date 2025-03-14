# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 23:24:10 by codespace         #+#    #+#              #
#    Updated: 2025/03/13 23:55:55 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat

CC			= c++
CFLAGS		= -std=c++98 -Wall -Werror -Wextra
INCLUDES	= -I includes 

VPATH		= sources
FILES		= Bureaucrat.cpp           \
			AForm.cpp                  \
			ShrubberyCreationForm.cpp  \
			RobotomyRequestForm.cpp    \
			PresidentialPardonForm.cpp \
			Intern.cpp                 \
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