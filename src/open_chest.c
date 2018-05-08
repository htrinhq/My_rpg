/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** open_chest
*/

#include "rpg.h"

void display_inside(int obj, /*sprite_t **sprite, */icm_t *icm, sfRenderWindow *window)
{
	int x = 0;
	sprite_t *object;

	if (obj == -1)
		return;
	for (x = 0; icm->obj[x]; x = x + 1) {
		if (icm->obj[x]->id == obj)
			break;
	}
	object = find_sprite(icm->obj[x]->path);
	sfRenderWindow_drawSprite(window, object->s_sprt, NULL);
}

void display_chest(int x, int y, /*sprite_t **sprite, */icm_t *icm, sfRenderWindow *window)
{
	if (x > 107 && x < 119 && y > 140 && y < 150) {
		//printf("chest 0\n");
	}
	if (x > 107 && x < 119 && y > 110 && y < 120) {
		//printf("chest 1\n");
	}
	if (x > 217 && x < 227 && y > 110 && y < 120) {
		//printf("chest 2\n");
	}
	if (x > 217 && x < 227 && y > 140 && y < 150) {
		//printf("chest 3\n");
	}
	if (x > 217 && x < 227 && y > 170 && y < 180) {
		//printf("chest 4\n");
	}
	if (x > 217 && x < 227 && y > 200 && y < 210) {
		//printf("chest 5\n");
	}
	if (x > 217 && x < 227 && y > 231 && y < 241) {
		display_inside(icm->chests[6]->inside[0], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[1], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[2], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[3], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[4], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[5], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[6], /*sprite, */icm, window);
		display_inside(icm->chests[6]->inside[7], /*sprite, */icm, window);
		//display_inside(icm->chests[6][8], sprite, icm, window);
	}
	if (x > 217 && x < 227 && y > 261 && y < 271) {
		//printf("chest 7\n");
	}
	if (x > 217 && x < 227 && y > 292 && y < 302) {
		//printf("chest 8\n");
	}
	if (x > 217 && x < 227 && y > 312 && y < 332) {
		//printf("chest 9\n");
	}
}

int detect_chest(int x, int y, sprite_t **sprite, icm_t *icm, sfRenderWindow *window)
{
	if ((x > 107 && x < 119 && y > 140 && y < 150) ||
	(x > 107 && x < 119 && y > 110 && y < 120) ||
	(x > 217 && x < 227 && y > 110 && y < 120) ||
	(x > 217 && x < 227 && y > 140 && y < 150) ||
	(x > 217 && x < 227 && y > 170 && y < 180) ||
	(x > 217 && x < 227 && y > 200 && y < 210) ||
	(x > 217 && x < 227 && y > 231 && y < 241) ||
	(x > 217 && x < 227 && y > 261 && y < 271) ||
	(x > 217 && x < 227 && y > 292 && y < 302) ||
	(x > 217 && x < 227 && y > 312 && y < 332)) {
		if (sprite[2]->o_sprt == 1) {
			sprite[8]->o_sprt = 0;
			display_chest(x, y, /*sprite, */icm, window);
		} else
			sprite[8]->o_sprt = 1;
	} else
		sprite[8]->o_sprt = 0;
	return (1);
}
