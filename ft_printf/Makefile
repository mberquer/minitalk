SRCS	=	ft_printf.c\
			ft_print_char.c\
			ft_print_nbr.c\
			ft_print_str.c\
			ft_print_unsigned.c\
			ft_print_hexa.c\
			ft_print_ptr.c\

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean	all

.PHONY:		all clean fclean re
