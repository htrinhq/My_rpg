/*
** EPITECH PROJECT, 2017
** chest.c
** File description:
** chest functions
*/

#include "rpg.h"

int *fill_object(int *inside)
{
	int x = rand_gen(0, 4);
	int y = 0;

	if (x == 0)
		return (inside);
	for (y = 0; y < x; y = y + 1)
		inside[y] = rand_gen(0, 14);
	return (inside);
}

chest_t **create_chests(chest_t **chests)
{
	int x = 0;
	int y = 0;
	chests = malloc(sizeof(chest_t *) * 10);

	for (x = 0; x < 10; x = x + 1) {
		chests[x] = malloc(sizeof(chest_t));
		chests[x]->inside = malloc(sizeof(int) * 9);
		for (y = 0; y < 8; y = y + 1) {
			chests[x]->inside[y] = -1;
		}
		chests[x]->inside[8] = -2;
		chests[x]->name = x;
		chests[x]->inside = fill_object(chests[x]->inside);
	}
	return (chests);
}

void add_in_chest(chest_t **chests, int chestnb, int id)
{
	int x = 0;

	for (x = 0; chests[chestnb]->inside[x] != -2; x = x + 1) {
		if (chests[chestnb]->inside[x] == -1) {
			chests[chestnb]->inside[x] = id;
			break;
		}
	}
}

void remove_in_chest(chest_t **chests, int chestnb, int id)
{
	int x = 0;

	for (x = 0; chests[chestnb]->inside[x] != -2; x = x + 1) {
		if (chests[chestnb]->inside[x] == id) {
			chests[chestnb]->inside[x] = -1;
			break;
		}
	}
}
