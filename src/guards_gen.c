/*
** EPITECH PROJECT, 2018
** guards_gen.c
** File description:
** guards_gen.c
*/

#include "rpg.h"

quard_t *guards_gen(void)
{
	guard_t *guard = malloc(sizeof(guard_t));
	npcst_t stat;

	stat->max_lp = 100;
	stat->lp = 100;
	stat->strength = 40;
	guard->stat = stat;
	guard->sprite = find_sprite("rsrc/pictures/gardian.png");
	return (guard);
}

guard_t **get_all_guards(int guards_nb)
{
	int i = 0;
	guard_t **guards = malloc(sizeof(guard_t*) * (guards_nb + 1));

	while (i < guards_nb) {
		guards[i] = malloc(sizeof(guard_t));
		guards[i] = guards_gen();
		i = i + 1;
	}
	get_guards(1, guards);
}

sprite_t *find_sprite(char *name)
{
	sprite_t **sprites = get_sprite(0, NULL);
	int i = 0;

	while (sprites[i] != NULL) {
		if (my_strcmp(sprites[i]->name, name))
			return (sprites[i]);
		i = i + 1;
	}
	return (NULL);
}