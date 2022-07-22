DIR_SOURCE = srcs/
SOURCES	= ${DIR_SOURCE}ft_putchar.c ${DIR_SOURCE}ft_swap.c ${DIR_SOURCE}ft_putstr.c ${DIR_SOURCE}ft_strlen.c ${DIR_SOURCE}ft_strcmp.c
OBJECTS	= ${SOURCES:.c=.o}
TARGET	= libft.a
RM		= rm -f

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $@ -I includes

libft.a: srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
	ar -rcus libft.a ${OBJECTS}

all: ${TARGET}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${TARGET}

re: fclean all