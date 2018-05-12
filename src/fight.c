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
	sprite[0]->r_sprt.left <= 1110 && sprite[16]->o_sprt > 0 &&
	(int)sfTime_asSeconds(
	sfClock_getElapsedTime(sprite[2]->clock)) >= 2) {
		sprite[16]->o_sprt -= stat->force;
		stat->life -= 3;
		particules(window, 975, 570, 0);
		sfClock_restart(sprite[2]->clock);
	}
	if (stat->life < 1)
		sprite[17]->o_sprt = 1;
	else if (sprite[16]->o_sprt < 0)
		sprite[17]->o_sprt = 2;
}
