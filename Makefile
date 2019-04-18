##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile files
##

NAME	=	navy

SRC	=	main.c\
		basic_puts.c\
		signal_functions.c\
		game_loop.c\
		map.c\
		get_next_line.c\
		transfer.c\
		update_map.c\
		signal_functions2.c\
		check_pos.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME)

clean:
		rm $(OBJ)

fclean:		clean
		rm $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
