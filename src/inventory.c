/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** inventory.c
*/

#include "rpg.h"

int *shift_inventory(int *inventory)
{
	int i = 0;
	int j = 0;
	int buf = 0;

	while (i < 16 && inventory[i] != -1)
		i = i + 1;
	buf = i;
	while (i < 16 && inventory[i] == -1)
		i = i + 1;
	if (i == 16)
		return (inventory);
	while (i + j < 16) {
		inventory[buf + j] = inventory[i + j];
		inventory[i + j] = -1;
		j = j + 1;
	}
	return (inventory);
}

int *spawn_objects(void)
{
	int *chest = malloc(sizeof(int) * 9);
	int i = 0;
	int max = rand_gen(2, 4);

	while (i < max) {
		chest[i] = spawn_obj_id();
		i = i + 1;
	}
	while (max < 9) {
		chest[max] = -1;
		max = max + 1;
	}
	return (chest);
}

int spawn_obj_id(void)
{
	int j = 0;
	int spawn = 0;

	while (j < 15) {
		spawn = rand_gen(1, 7);
		if (spawn == 1)
			return (j);
		j = j + 1;
	}
	return (14);
}

int *player_take_obj(int *inventory, int obj_id)
{
	int i = 0;

	while (i < 16 && inventory[i] != -1)
		i = i + 1;
	if (i == 16)
		return (inventory);
	inventory[i] = obj_id;
	return (inventory);
}

void display_obj(int *inventory, idobj_t **obj)
{
	int i = 0;
	sfVector2f pos = { 150, 1000 };
	sprite_t *spr;

	while (inventory[i] != -1) {
		if (i != 0 && i % 4 == 0) {
			pos.x = 150;
			pos.y = pos.y + 150;
		}
		spr = find_sprite(obj[inventory[i]]->path);
		sfSprite_setPosition(spr->s_sprt, pos);
		pos.x = pos.x + 150;
		i = i + 1;
	}
}