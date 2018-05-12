/*
** EPITECH PROJECT, 2017
** second_set.c
** File description:
** set functions
*/

#include "rpg.h"

void set_position(sprite_t **sprite)
{
	sfSprite_setPosition(sprite[1]->s_sprt, sprite[1]->v_sprt);
	sfSprite_setPosition(sprite[21]->s_sprt, sprite[21]->v_sprt);
	sfSprite_setPosition(sprite[7]->s_sprt, sprite[7]->v_sprt);
	sfSprite_setPosition(sprite[8]->s_sprt, sprite[8]->v_sprt);
	sfSprite_setPosition(sprite[20]->s_sprt, sprite[20]->v_sprt);
	sfSprite_setPosition(sprite[9]->s_sprt, sprite[9]->v_sprt);
	sfSprite_setPosition(sprite[10]->s_sprt, sprite[10]->v_sprt);
	sfSprite_setPosition(sprite[11]->s_sprt, sprite[11]->v_sprt);
	sfSprite_setPosition(sprite[12]->s_sprt, sprite[12]->v_sprt);
	sfSprite_setPosition(sprite[16]->s_sprt, sprite[16]->v_sprt);
}

void set_scale(sprite_t **sprite)
{
	sfVector2f scale = {0.5, 0.5};
	sfVector2f scale2 = {2, 2};
	sfVector2f scale3 = {5, 5};

	sfSprite_setScale(sprite[1]->s_sprt, scale);
	sfSprite_setScale(sprite[21]->s_sprt, scale);
	sfSprite_setScale(sprite[7]->s_sprt, scale2);
	sfSprite_setScale(sprite[8]->s_sprt, scale2);
	sfSprite_setScale(sprite[20]->s_sprt, scale2);
	sfSprite_setScale(sprite[9]->s_sprt, scale3);
	sfSprite_setScale(sprite[10]->s_sprt, scale3);
	sfSprite_setScale(sprite[11]->s_sprt, scale3);
	sfSprite_setScale(sprite[12]->s_sprt, scale3);
	sfSprite_setScale(sprite[16]->s_sprt, scale);
}
