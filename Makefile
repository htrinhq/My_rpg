##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/stock_var.c		\
		src/utilities.c		\
		src/struct_obj.c	\
		src/sprites.c		\
		src/guards_gen.c	\
		src/character_gen.c	\
		src/chest.c		\
		src/inventory.c		\
		src/get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-W -Wall -Wextra -I include -g -fdiagnostics-color=always

LDFLAGS	=	-l c_graph_prog -L ./lib/my/ -lmyprintf -L ./lib/graph/ -lgraph

all:	libmake $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/my/
	make -C./lib/graph/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/
	make clean -C ./lib/graph/

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my/
	make fclean -C ./lib/graph/

re:	fclean all

.PHONY:	clean fclean re all libmake
