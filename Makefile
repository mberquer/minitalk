# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:49:37 by mberquer          #+#    #+#              #
#    Updated: 2022/06/16 12:12:36 by mberquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCSC = src/

SRCSS = src/

OBJC = $(SRCSC:%.c=%.o)

OBJS = $(SRCSS:%.c=%.o)

CC = cc

FLAG = -g3 -Wall -Wextra -Werror

SANI = -fsanitize=address

$(NAME): $(OBJ)
	$(CC) $(OBJC) -o client #$(SANI)
	$(CC) $(OBJS) -o server #$(SANI)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean: 
	rm -rf $(OBJC) $(OBJS)

fclean: clean
	rm -rf client server

all: $(NAME) 
	
re: fclean
	make all
	
.PHONY: clean fclean all re