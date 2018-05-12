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
	for (y = 0; y < x; y = y + 1) {
		inside[y] = rand_gen(0, 14);
		if (inside[y] == 5 || inside[y] == 6)
			inside[y] = 10;
	}
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

int add_inventory(int id, icm_t *icm)
{
	int x = 0;

	for (x = 0; icm->inventory[x] != -2; x = x + 1) {
		if (icm->inventory[x] == -1) {
			icm->inventory[x] = id;
			return (1);
		}
	}
	return (0);
}

int add_chest(int id, icm_t *icm, int nb)
{
	int x = 0;

	for (x = 0; icm->chests[nb]->inside[x] != -2; x = x + 1) {
		if (icm->chests[nb]->inside[x] == -1) {
			icm->chests[nb]->inside[x] = id;
			return (1);
		}
	}
	return (0);
}
