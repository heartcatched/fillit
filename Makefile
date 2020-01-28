
NAME	= fillit

SRC		= ./src/main.c  \
		  ./src/check.c \
		  ./src/read.c  \
		  ./src/map.c   \
		  ./src/solve.c \
		  ./src/ft_strsub.c \
		  ./src/ft_memdel.c \
		  ./src/ft_putendl_fd.c \
		  ./src/ft_putstr_fd.c \
		  ./src/ft_putendl.c \
		  ./src/ft_strlen.c \
		  ./src/ft_strnew.c \
		  ./src/ft_putchar_fd.c \
		  ./src/ft_memset.c

OBJ		= $(SRC:.c=.o)

INCLUDE = ./includes

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all