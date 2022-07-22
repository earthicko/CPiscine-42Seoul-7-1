NAME = do-op
CC = gcc -Wall -Wextra -Werror
SRC = src/
SOURCES = ${SRC}main.c ${SRC}calculator.c ${SRC}ft_atoi.c ${SRC}ft_str.c ${SRC}operators.c
OBJECTS = ${SOURCES:.c=.o}
RM = rm -f

all: ${NAME}

.c.o:
	${CC} -c $< -o $@

${NAME}: ${OBJECTS}
	${CC} -o $@ $^

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all
