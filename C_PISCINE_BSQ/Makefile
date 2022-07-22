NAME = bsq
CC = gcc -Wall -Wextra -Werror
SRC = src/
SOURCES = ${SRC}main.c ${SRC}array.c ${SRC}draw.c ${SRC}ft_str.c ${SRC}io.c ${SRC}map_create.c ${SRC}map_parsing.c ${SRC}map_parse_row.c ${SRC}map_delete.c ${SRC}mathtools.c ${SRC}solve_tools.c ${SRC}solve.c ${SRC}t_string.c
OBJECTS = ${SOURCES:.c=.o}
RM = rm -f

all: ${NAME}

.c.o:
	${CC} -c $< -o $@ -I includes

${NAME}: ${OBJECTS}
	${CC} -o $@ $^

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all