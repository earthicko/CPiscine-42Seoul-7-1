TARGET = ft_display_file
SOURCES = main.c
OBJECTS = ${SOURCES:.c=.o}
CC = gcc -Wall -Wextra -Werror


all: ${TARGET}

.c.o:
	${CC} -c $< -o $@ -I includes

${TARGET}: ${OBJECTS}
	${CC} -o $@ $^

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${TARGET}

re: fclean all
