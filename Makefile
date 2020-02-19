  
NAME			= fillit

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			= grid_ko.c \
				  max_n_check.c \
				  fillit.c \
				  algorithm1.c \
				  algorithm2.c \
				  algorithm3.c \
				  main.c \
				  list_n_exit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS): %.o : %.c	includes/fillit.h
	$(CC) $(CFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all