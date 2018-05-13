/*
** EPITECH PROJECT, 2017
** set.c
** File description:
** set functions
*/

#include "rpg.h"

void set_rect(sprite_t **sprite, plstat_t *stat)
{
	sprite[1]->r_sprt.top = 10;
	sprite[1]->r_sprt.left = 70;
	sprite[1]->r_sprt.width = 136;
	sprite[1]->r_sprt.height = 183;
	sprite[21]->r_sprt.top = 10;
	sprite[21]->r_sprt.left = 70;
	sprite[21]->r_sprt.width = 136;
	sprite[21]->r_sprt.height = 183;
	sprite[7]->r_sprt.top = 20 * (stat->life - 1);
	sprite[7]->r_sprt.left = 0;
	sprite[7]->r_sprt.width = 100;
	sprite[7]->r_sprt.height = 20;
	sprite[9]->r_sprt.top = 20 * (stat->force - 1);
	sprite[9]->r_sprt.left = 0;
	sprite[9]->r_sprt.width = 100;
	sprite[9]->r_sprt.height = 20;
	sprite[10]->r_sprt.top = 20 * (stat->inteligence - 1);
	sprite[10]->r_sprt.left = 0;
	sprite[10]->r_sprt.width = 100;
	sprite[10]->r_sprt.height = 20;
}

void set_rect_2(sprite_t **sprite, plstat_t *stat, int level)
{
	sprite[11]->r_sprt.top = 20 * (stat->speed - 1);
	sprite[11]->r_sprt.left = 0;
	sprite[11]->r_sprt.width = 100;
	sprite[11]->r_sprt.height = 20;
	sprite[12]->r_sprt.top = 20 * level;
	sprite[12]->r_sprt.left = 0;
	sprite[12]->r_sprt.width = 100;
	sprite[12]->r_sprt.height = 20;
	sprite[16]->r_sprt.top = 10;
	sprite[16]->r_sprt.left = 70;
	sprite[16]->r_sprt.width = 136;
	sprite[16]->r_sprt.height = 183;
	sprite[16]->v_sprt.x = 198;
	sprite[16]->v_sprt.y = 42;
	sprite[7]->v_sprt.x = 40;
	sprite[7]->v_sprt.y = 960;
	sprite[21]->v_sprt.x = 960;
	sprite[21]->v_sprt.y = 540;
	sprite[1]->v_sprt.x = 960;
	sprite[1]->v_sprt.y = 540;
}

void set_rect_3(sprite_t **sprite)
{
	sprite[4]->v_sprt.x = 225 / 2 - 6;
	sprite[4]->v_sprt.y = 213 / 2 - 15;
	sprite[8]->v_sprt.x = 960;
	sprite[8]->v_sprt.y = 440;
	sprite[20]->v_sprt.x = 960;
	sprite[20]->v_sprt.y = 440;
	sprite[9]->v_sprt.x = 700;
	sprite[9]->v_sprt.y = 350;
	sprite[10]->v_sprt.x = 700;
	sprite[10]->v_sprt.y = 450;
	sprite[11]->v_sprt.x = 700;
	sprite[11]->v_sprt.y = 550;
	sprite[12]->v_sprt.x = 700;
	sprite[12]->v_sprt.y = 650;
	sprite[13]->v_sprt.x = 730;
	sprite[13]->v_sprt.y = 650;
}

void set_o_sprt(sprite_t **sprite)
{
	sprite[1]->o_sprt = 0;
	sprite[2]->o_sprt = 0;
	sprite[5]->o_sprt = 0;
	sprite[8]->o_sprt = 0;
	sprite[20]->o_sprt = 0;
	sprite[9]->o_sprt = 0;
	sprite[15]->o_sprt = 0;
	sprite[14]->o_sprt = 0;
	sprite[16]->o_sprt = 8;
	sprite[18]->o_sprt = 0;
	sprite[17]->o_sprt = 0;
	sprite[19]->o_sprt = 0;
	sprite[20]->o_sprt = 0;
}

void set_texture_rect(sprite_t **sprite)
{
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	sfSprite_setTextureRect(sprite[21]->s_sprt, sprite[21]->r_sprt);
	sfSprite_setTextureRect(sprite[7]->s_sprt, sprite[7]->r_sprt);
	sfSprite_setTextureRect(sprite[9]->s_sprt, sprite[9]->r_sprt);
	sfSprite_setTextureRect(sprite[10]->s_sprt, sprite[10]->r_sprt);
	sfSprite_setTextureRect(sprite[11]->s_sprt, sprite[11]->r_sprt);
	sfSprite_setTextureRect(sprite[12]->s_sprt, sprite[12]->r_sprt);
	sfSprite_setTextureRect(sprite[16]->s_sprt, sprite[16]->r_sprt);
}
