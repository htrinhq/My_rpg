/*
** EPITECH PROJECT, 2017
** fill_obj.c
** File description:
** desc
*/

#include "rpg.h"

int *create_inventory(int *inventory)
{
	int x = 0;

	for (x = 0; x < 16; x = x + 1)
		inventory[x] = -1;
	inventory[16] = -2;
	return (inventory);
}

void fill_obj_sprite2(sprite_t **obj)
{
	obj[0] = create_sprite(obj[0], "rsrc/pictures/bear.png");
	obj[1] = create_sprite(obj[1], "rsrc/pictures/book.png");
	obj[2] = create_sprite(obj[2], "rsrc/pictures/chauss.png");
	obj[3] = create_sprite(obj[3], "rsrc/pictures/fork.png");
	obj[4] = create_sprite(obj[4], "rsrc/pictures/glass.png");
	obj[5] = create_sprite(obj[5], "rsrc/pictures/key.png");
	obj[6] = create_sprite(obj[6], "rsrc/pictures/knife.png");
	obj[7] = create_sprite(obj[7], "rsrc/pictures/lime.png");
	obj[8] = create_sprite(obj[8], "rsrc/pictures/phone.png");
	obj[9] = create_sprite(obj[9], "rsrc/pictures/savon.png");
	obj[10] = create_sprite(obj[10], "rsrc/pictures/scotch.png");
	obj[11] = create_sprite(obj[11], "rsrc/pictures/screwdriver.png");
	obj[12] = create_sprite(obj[12], "rsrc/pictures/shaver.png");
	obj[13] = create_sprite(obj[13], "rsrc/pictures/toothpaste.png");
	obj[14] = create_sprite(obj[14], "rsrc/pictures/wisky.png");
}

void fill_obj_sprite3(sprite_t **obj)
{
	sfVector2f scale = {0.15, 0.15};

	sfSprite_setScale(obj[0]->s_sprt, scale);
	sfSprite_setScale(obj[1]->s_sprt, scale);
	sfSprite_setScale(obj[2]->s_sprt, scale);
	sfSprite_setScale(obj[3]->s_sprt, scale);
	sfSprite_setScale(obj[4]->s_sprt, scale);
	sfSprite_setScale(obj[5]->s_sprt, scale);
	sfSprite_setScale(obj[6]->s_sprt, scale);
	sfSprite_setScale(obj[7]->s_sprt, scale);
	sfSprite_setScale(obj[8]->s_sprt, scale);
	sfSprite_setScale(obj[9]->s_sprt, scale);
	sfSprite_setScale(obj[10]->s_sprt, scale);
	sfSprite_setScale(obj[11]->s_sprt, scale);
	sfSprite_setScale(obj[12]->s_sprt, scale);
	sfSprite_setScale(obj[13]->s_sprt, scale);
	sfSprite_setScale(obj[14]->s_sprt, scale);
}

sprite_t **fill_obj_sprite(sprite_t **obj)
{
	obj[0] = malloc(sizeof(sprite_t));
	obj[1] = malloc(sizeof(sprite_t));
	obj[2] = malloc(sizeof(sprite_t));
	obj[3] = malloc(sizeof(sprite_t));
	obj[4] = malloc(sizeof(sprite_t));
	obj[5] = malloc(sizeof(sprite_t));
	obj[6] = malloc(sizeof(sprite_t));
	obj[7] = malloc(sizeof(sprite_t));
	obj[8] = malloc(sizeof(sprite_t));
	obj[9] = malloc(sizeof(sprite_t));
	obj[10] = malloc(sizeof(sprite_t));
	obj[11] = malloc(sizeof(sprite_t));
	obj[12] = malloc(sizeof(sprite_t));
	obj[13] = malloc(sizeof(sprite_t));
	obj[14] = malloc(sizeof(sprite_t));
	fill_obj_sprite2(obj);
	fill_obj_sprite3(obj);
	return (obj);
}
