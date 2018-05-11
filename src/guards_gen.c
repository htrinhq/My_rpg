/*
** EPITECH PROJECT, 2018
** guards_gen.c
** File description:
** guards_gen.c
*/

#include "rpg.h"

guard_t *guards_gen(void)
{
	guard_t *guard = malloc(sizeof(guard_t));
	npcst_t stat;
	static int token = 55;

	stat.max_lp = 100;
	stat.lp = 100;
	stat.strength = 40;
	guard->stat = stat;
	guard->sprite = find_sprite("rsrc/pictures/gardian.png");
	guard->token = token;
	guard->sprite->r_sprt = create_recth(0, 0, 320, 320);
	token = token + 1;
	return (guard);
}

guard_t **get_all_guards(int guards_nb)
{
	int i = 0;
	guard_t **guards = malloc(sizeof(guard_t*) * (guards_nb + 1));
	sfVector2f scale = {0.5, 0.5};

	while (i < guards_nb) {
		guards[i] = malloc(sizeof(guard_t));
		guards[i] = guards_gen();
		i = i + 1;
	}
	get_guards(1, guards);
	return (guards);
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

void init_var(void)
{
	create_sprite_tab();
	get_all_npcs(7);
	get_all_guards(3);
	read_npc_routes();
}