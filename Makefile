# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberquer <mberquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:49:37 by mberquer          #+#    #+#              #
#    Updated: 2022/07/11 18:22:43 by mberquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAMES = server
NAMEC = client

PRINTF = ft_printf/ft_print_char.c \
		ft_printf/ft_print_hexa.c \
		ft_printf/ft_print_nbr.c \
		ft_printf/ft_print_ptr.c \
		ft_printf/ft_print_str.c \
		ft_printf/ft_print_unsigned.c \
		ft_printf/ft_printf.c \

LIBFT = libft/libft.a

SRCSC = src/client.c

SRCSS = src/server.c


OBJC = $(SRCSC:%.c=%.o)

OBJS = $(SRCSS:%.c=%.o)

OBJP = $(PRINTF:%.c=%.o)

CC = cc

FLAG = -g3 -Wall -Wextra -Werror

SANI = -fsanitize=address

$(NAME): $(NAMES) $(NAMEC)

$(NAMES): $(OBJS) $(OBJP)
	make -C libft
	$(CC) $(OBJS) $(OBJP) $(LIBFT) -o server #$(SANI)

$(NAMEC): $(OBJC) $(OBJP)
	make -C libft
	$(CC) $(OBJC) $(OBJP) $(LIBFT) -o client #$(SANI)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJC) $(OBJS) $(OBJP)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAMEC) $(NAMES)

all: $(NAME)
	
re: fclean
	make all
	
.PHONY: clean fclean all re