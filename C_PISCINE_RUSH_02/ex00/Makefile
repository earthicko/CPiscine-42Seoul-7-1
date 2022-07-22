CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
HEADER = includes
RM = rm -f
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/check_entry.c $(SRC_DIR)/create_dict.c $(SRC_DIR)/create_entry.c $(SRC_DIR)/free.c $(SRC_DIR)/num_conversion.c $(SRC_DIR)/print.c $(SRC_DIR)/util_char.c $(SRC_DIR)/util_strcat.c $(SRC_DIR)/util_strcpy.c $(SRC_DIR)/util_strtools.c $(SRC_DIR)/util_split.c $(SRC_DIR)/util_split_by_char.c
NAME = rush-02

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -I $(HEADER)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all
