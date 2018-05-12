/*
** EPITECH PROJECT, 2017
** display_chest.c
** File description:
** desc
*/

#include "rpg.h"

void display_chest3(int x, int y, icm_t *icm, sfRenderWindow *window)
{
	if (x > 217 && x < 227 && y > 292 && y < 302) {
		icm->ch = 8;
		display_inside(icm->chests[8], icm, window);
	}
	if (x > 217 && x < 227 && y > 312 && y < 332) {
		icm->ch = 9;
		display_inside(icm->chests[9], icm, window);
	}
}

void display_chest2(int x, int y, icm_t *icm, sfRenderWindow *window)
{
	if (x > 217 && x < 227 && y > 170 && y < 180) {
		icm->ch = 4;
		display_inside(icm->chests[4], icm, window);
	}
	if (x > 217 && x < 227 && y > 200 && y < 210) {
		icm->ch = 5;
		display_inside(icm->chests[5], icm, window);
	}
	if (x > 217 && x < 227 && y > 231 && y < 241) {
		icm->ch = 6;
		display_inside(icm->chests[6], icm, window);
	}
	if (x > 217 && x < 227 && y > 261 && y < 271) {
		icm->ch = 7;
		display_inside(icm->chests[7], icm, window);
	}
	display_chest3(x, y, icm, window);
}

void display_chest(int x, int y, icm_t *icm, sfRenderWindow *window)
{
	if (x > 166 && x < 176 && y > 140 && y < 150) {
		icm->ch = 0;
		display_inside(icm->chests[0], icm, window);
	}
	if (x > 166 && x < 176 && y > 110 && y < 120) {
		icm->ch = 1;
		display_inside(icm->chests[1], icm, window);
	}
	if (x > 217 && x < 227 && y > 110 && y < 120) {
		icm->ch = 2;
		display_inside(icm->chests[2], icm, window);
	}
	if (x > 217 && x < 227 && y > 140 && y < 150) {
		icm->ch = 3;
		display_inside(icm->chests[3], icm, window);
	}
	display_chest2(x, y, icm, window);
}

int detect_chest(int x, int y, sprite_t **sprite)
{
	if ((x > 166 && x < 176 && y > 140 && y < 150) ||
	(x > 166 && x < 176 && y > 110 && y < 120) ||
	(x > 217 && x < 227 && y > 110 && y < 120) ||
	(x > 217 && x < 227 && y > 140 && y < 150) ||
	(x > 217 && x < 227 && y > 170 && y < 180) ||
	(x > 217 && x < 227 && y > 200 && y < 210) ||
	(x > 217 && x < 227 && y > 231 && y < 241) ||
	(x > 217 && x < 227 && y > 261 && y < 271) ||
	(x > 217 && x < 227 && y > 292 && y < 302) ||
	(x > 217 && x < 227 && y > 312 && y < 332)) {
		sprite[14]->v_sprt.x = x;
		sprite[14]->v_sprt.y = y;
		sprite[8]->o_sprt = 1;
	} else if (x > 208 && x < 222 && y > 370 && y < 376)
		sprite[8]->o_sprt = 2;
	else
		sprite[8]->o_sprt = 0;
	return (1);
}
