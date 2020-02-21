  
NAME = fillit
COMPILER = gcc
FLAGS = -g -Wall -Wextra -Werror
INC = -I includes/
LIB = libft/libft.a
SRCS			= grid_ko.c \
				  max_n_check.c \
				  fillit.c \
				  algorithm1.c \
				  algorithm2.c \
				  algorithm3.c \
				  main.c \
				  list_n_exit.c

OBJ		= $(SRC:.c=.o)

.PHONY: all clean fclean re

%.o: %.c
	@$(COMPILER) $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C libft/
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) $(SRCS) $(INC) $(LIB)

clean:
	@make -C libft clean

fclean:
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)