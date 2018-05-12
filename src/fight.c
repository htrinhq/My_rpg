/*
** EPITECH PROJECT, 2018
** fight.c
** File description:
** fight.c
*/

#include "rpg.h"

void fight(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	if (sprite[0]->r_sprt.top <= 300 && sprite[0]->r_sprt.left >= 850 &&
	sprite[0]->r_sprt.left <= 1110 && sprite[16]->o_sprt > 0) {
		sprite[16]->o_sprt -= stat->force;
		stat->life -= 3;
		if (stat->life < 1) {
			sprite[17]->o_sprt = 1;
			sfRenderWindow_close(window);
		}
	}
}
