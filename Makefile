# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daortega <daortega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:34:28 by daortega          #+#    #+#              #
#    Updated: 2024/09/10 16:31:34 by daortega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAMELIB = libs/philo.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

#--------------<SRC>-------------
SRC = src/
CFILES = main.c data.c utils.c forks.c philo.c getters.c
SRCC = $(addprefix $(SRC), $(CFILES))

DIR_O = tmp/
OBJC = $(addprefix $(DIR_O), $(SRCC:.c=.o))

# RULES
all: $(DIR_O) $(NAME)
	
$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)%.o: %.c $(NAMELIB) Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g -pthread -c $< -o $@

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME)

clean:
	rm -rf $(DIR_O)
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re