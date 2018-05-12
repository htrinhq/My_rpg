/*
** EPITECH PROJECT, 2017
** display_inside.c
** File description:
** desc
*/

#include "rpg.h"

void display_inside2(chest_t *chests, icm_t *icm, sfRenderWindow *window)
{
	sfVector2f pos3 = {960, 435};
	sfVector2f pos4 = {1075, 435};

	if (chests->inside[2] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[2]]->s_sprt,
		pos3);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[2]]->s_sprt, NULL);
	}
	if (chests->inside[3] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[3]]->s_sprt,
		pos4);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[3]]->s_sprt, NULL);
	}
}

void display_inside3(chest_t *chests, icm_t *icm, sfRenderWindow *window)
{
	sfVector2f pos5 = {750, 550};
	sfVector2f pos6 = {855, 550};

	if (chests->inside[4] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[4]]->s_sprt,
		pos5);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[4]]->s_sprt, NULL);
	}
	if (chests->inside[5] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[5]]->s_sprt,
		pos6);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[5]]->s_sprt, NULL);
	}
}

void display_inside4(chest_t *chests, icm_t *icm, sfRenderWindow *window)
{
	sfVector2f pos7 = {960, 550};
	sfVector2f pos8 = {1075, 550};

	if (chests->inside[6] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[6]]->s_sprt,
		pos7);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[6]]->s_sprt, NULL);
	}
	if (chests->inside[7] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[7]]->s_sprt,
		pos8);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[7]]->s_sprt, NULL);
	}
}

void display_inside(chest_t *chests, icm_t *icm, sfRenderWindow *window)
{
	sfVector2f pos1 = {750, 435};
	sfVector2f pos2 = {855, 435};

	if (chests->inside[0] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[0]]->s_sprt,
		pos1);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[0]]->s_sprt, NULL);
	}
	if (chests->inside[1] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[1]]->s_sprt,
		pos2);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[chests->inside[1]]->s_sprt, NULL);
	}
	display_inside2(chests, icm, window);
	display_inside3(chests, icm, window);
	display_inside4(chests, icm, window);
}
