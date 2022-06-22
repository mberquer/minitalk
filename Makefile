# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:49:37 by mberquer          #+#    #+#              #
#    Updated: 2022/06/22 03:18:06 by mberquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

PRINTF = ft_printf/ft_print_char.c \
		ft_printf/ft_print_hexa.c \
		ft_printf/ft_print_nbr.c \
		ft_printf/ft_print_ptr.c \
		ft_printf/ft_print_str.c \
		ft_printf/ft_print_unsigned.c \
		ft_printf/ft_printf.c \
		
SRCSC = src/client.c

SRCSS = src/server.c \


OBJC = $(SRCSC:%.c=%.o)

OBJS = $(SRCSS:%.c=%.o)

OBJP = $(PRINTF:%.c=%.o)

CC = cc

FLAG = -g3 -Wall -Wextra -Werror

SANI = -fsanitize=address

$(NAME): $(OBJC) $(OBJS) $(OBJP)
	$(CC) $(OBJC) $(OBJP) -o client #$(SANI)
	$(CC) $(OBJS) $(OBJP) -o server #$(SANI)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean: 
	rm -rf $(OBJC) $(OBJS) $(OBJP)

fclean: clean
	rm -rf client server

all: $(NAME) 
	
re: fclean
	make all
	
.PHONY: clean fclean all re