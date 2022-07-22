TARGET = ft_hexdump
CC = gcc -Wall -Wextra -Werror
SRC = src/
SOURCES = ${SRC}main.c ${SRC}ft_char.c ${SRC}ft_str.c ${SRC}hexdump.c ${SRC}hexreader_argparse.c ${SRC}hexreader_create.c ${SRC}hexreader_print.c
OBJECTS = ${SOURCES:.c=.o}
RM = rm -f

all: ${TARGET}

.c.o:
	${CC} -c $< -o $@ -I includes

${TARGET}: ${OBJECTS}
	${CC} -o $@ $^

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${TARGET}

re: fclean all
