/*
** EPITECH PROJECT, 2018
** read_paths.c
** File description:
** read_paths.c
*/

#include "rpg.h"

void read_npc_routes(void)
{
	npc_t **npc = get_npc(0, NULL);
	guard_t **guard = get_guards(0, NULL);

	npc[0]->map = read_routes("rsrc/paths/route_0");
	npc[1]->map = read_routes("rsrc/paths/route_1");
	npc[2]->map = read_routes("rsrc/paths/route_2");
	npc[3]->map = read_routes("rsrc/paths/route_3");
	npc[4]->map = read_routes("rsrc/paths/route_4");
	npc[5]->map = read_routes("rsrc/paths/route_5");
	npc[6]->map = read_routes("rsrc/paths/route_6");
	guard[0]->map = read_routes("rsrc/paths/route_7");
	guard[1]->map = read_routes("rsrc/paths/route_8");
	guard[2]->map = read_routes("rsrc/paths/route_9");
}

char **read_routes(char *path)
{
	char **map_txt = malloc(sizeof(char *) * 155);
	int fd = open(path, O_RDONLY);

	if (map_txt == NULL || fd == -1)
		return (NULL);
	for (int i = 0; i < 153; i = i + 1) {
		map_txt[i] = get_next_line(fd);
	}
	map_txt[153] = NULL;
	return (map_txt);
}

text_t **move_cursos_down(text_t **text)
{
	if (text[2]->pos.y == 375 + (3 * 77))
		text[2]->pos.y = 375;
	else
		text[2]->pos.y += 77;
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}

text_t **move_cursos_up(text_t **text)
{
	if (text[2]->pos.y == 375)
		text[2]->pos.y = 375 + (3 * 77);
	else
		text[2]->pos.y -= 77;
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}
