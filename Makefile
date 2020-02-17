NAME			= fillit

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			= srcs/grid_ko.c \
				  srcs/max_n_check.c \
				  srcs/fillit.c \
				  srcs/algorithm1.c \
				  srcs/algorithm2.c \
				  srcs/algorithm3.c \
				  srcs/main.c \
				  srcs/list_n_exit.c

OBJS = $(SRCS:srcs/.c=srcs/.o)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS): %.o : %.c
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
