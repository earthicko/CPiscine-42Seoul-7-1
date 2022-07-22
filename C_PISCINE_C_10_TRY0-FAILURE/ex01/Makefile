CC = gcc -Wall -Wextra -Werror
TARGET = ft_cat
SOURCES = src/main.c src/io.c
OBJECTS = ${SOURCES:.c=.o}
RM = rm -f

.c.o:
	${CC} -c $< -o $@ -I includes

all: ${TARGET}

${TARGET}: ${OBJECTS}
	${CC} -o $@ $^

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${TARGET}

re: fclean all
