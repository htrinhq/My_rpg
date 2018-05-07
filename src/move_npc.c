/*
** EPITECH PROJECT, 2018
** move_npc.c
** File description:
** move_npc.c
*/

#include "rpg.h"

sfVector2f get_pos_routine(char token, char **map)
{
	sfVector2f pos = find_character(map, token);
	sfVector2f prev_pos = find_character(map, 'Z');

	if (map[(int)pos.y - 1][(int)pos.x] == 'W') {
		map[(int)prev_pos.y][(int)prev_pos.x] = 'W';
		map[(int)pos.y][(int)pos.x] = 'Z';
		map[(int)pos.y - 1][(int)pos.x] = token;
		pos.y = pos.y - 1;
		return (pos);
	}
	if (map[(int)pos.y + 1][(int)pos.x] == 'W') {
		map[(int)prev_pos.y][(int)prev_pos.x] = 'W';
		map[(int)pos.y][(int)pos.x] = 'Z';
		map[(int)pos.y + 1][(int)pos.x] = token;
		pos.y = pos.y + 1;
		return (pos);
	}
	return (get_pos_routine2(map, token));
}

sfVector2f get_pos_routine2(char **map, char token)
{
	sfVector2f pos = find_character(map, token);
	sfVector2f prev_pos = find_character(map, 'Z');

	if (map[(int)pos.y][(int)pos.x - 1] == 'W') {
		map[(int)prev_pos.y][(int)prev_pos.x] = 'W';
		map[(int)pos.y][(int)pos.x] = 'Z';
		map[(int)pos.y][(int)pos.x - 1] = token;
		pos.x = pos.x - 1;
	} else if (map[(int)pos.y][(int)pos.x + 1] == 'W') {
		map[(int)prev_pos.y][(int)prev_pos.x] = 'W';
		map[(int)pos.y][(int)pos.x] = 'Z';
		map[(int)pos.y][(int)pos.x + 1] = token;
		pos.x = pos.x + 1;
	} else {
		map[(int)prev_pos.y][(int)prev_pos.x] = token;
		map[(int)pos.y][(int)pos.x] = 'Z';
		return (prev_pos);
	}
	return (pos);
}