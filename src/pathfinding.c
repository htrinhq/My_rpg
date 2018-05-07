/*
** EPITECH PROJECT, 2018
** pathfinding.c
** File description:
** pathfinding.c
*/

#include "rpg.h"

sfVector2f find_character(char **map, char token)
{
	sfVector2f pos = { 0, 0 };
	int y = 0;
	int len = my_tablen(map);

	while (y < len) {
		if (find_token(map[y], &pos, token)) {
			pos.y = y;
			break;
		}
		y = y + 1;
	}
	return (pos);
}

int find_token(char *str, sfVector2f *pos, char token)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == token) {
			pos->x = i;
			return (1);
		}
		i = i + 1;
	}
	return (0);
}

void follow(char follower, sfVector2f pos, char **map)
{
	//sfVector2f pos = find_character(map, token);
	sfVector2f pos_f = find_character(map, follower);

	if (pos_f.y < pos.y && map[(int)pos_f.y + 1][(int)pos_f.x] == ' ') {
		map[(int)pos_f.y + 1][(int)pos_f.x] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	} else if (pos_f.y > pos.y &&
	map[(int)pos_f.y - 1][(int)pos_f.x] == ' ') {
		map[(int)pos_f.y - 1][(int)pos_f.x] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	}
	follow2(follower, map, pos, pos_f);
}

void follow2(char follower, char **map, sfVector2f pos, sfVector2f pos_f)
{
	if (pos_f.x < pos.x && map[(int)pos_f.y][(int)pos_f.x + 1] == ' ') {
		map[(int)pos_f.y][(int)pos_f.x + 1] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	} else if (pos_f.x > pos.x &&
	map[(int)pos_f.y][(int)pos_f.x - 1] == ' ') {
		map[(int)pos_f.y][(int)pos_f.x - 1] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	}
	basic_move(follower, map, pos_f);
}

void basic_move(char follower, char **map, sfVector2f pos_f)
{
	if (map[(int)pos_f.y + 1][(int)pos_f.x] == ' ') {
		map[(int)pos_f.y + 1][(int)pos_f.x] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	} else if (map[(int)pos_f.y - 1][(int)pos_f.x] == ' ') {
		map[(int)pos_f.y - 1][(int)pos_f.x] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	}
	if (map[(int)pos_f.y][(int)pos_f.x + 1] == ' ') {
		map[(int)pos_f.y][(int)pos_f.x + 1] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	} else if (map[(int)pos_f.y][(int)pos_f.x - 1] == ' ') {
		map[(int)pos_f.y][(int)pos_f.x - 1] = follower;
		map[(int)pos_f.y][(int)pos_f.x] = ' ';
		return;
	}
}