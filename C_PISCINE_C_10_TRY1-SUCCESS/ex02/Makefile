CC = gcc -Wall -Wextra -Werror
TARGET = ft_tail
SOURCES = src/main.c src/ft_str.c src/handle_stream.c src/io.c src/t_string.c src/utility.c
OBJECTS = ${SOURCES:.c=.o}
RM = rm -f

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
