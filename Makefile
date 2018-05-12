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
		src/get_next_line.c	\
		src/display_inv.c	\
		src/display_inv2.c	\
		src/display_chest.c	\
		src/display_inside.c	\
		src/fill_obj.c		\
		src/move_npc.c		\
		src/pathfinding.c	\
		src/stat.c		\
		src/day_time.c		\
		src/time.c		\
		src/display_npc.c	\
		src/read_paths.c	\
		src/fight.c		\
		src/chest_event.c	\
		src/change_chest.c	\
		src/game_event.c	\
		src/move_player.c	\
		src/event.c		\
		src/loop.c		\
		src/initialize_text.c	\
		src/game_loop.c		\
		src/initialize_sprite.c	\
		src/set.c		\
		src/second_set.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-W -Wall -Wextra -I include -g -fdiagnostics-color=always

LDFLAGS =	-l c_graph_prog -L ./lib/my/ -lmyprintf -L ./lib/graph/ -lgraph

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
