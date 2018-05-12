/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** open_chest
*/

#include "rpg.h"

void display_inventory(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos1 = {110, 375};
	sfVector2f pos2 = {215, 375};

	if (icm->inventory[0] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[0]]->s_sprt,
		pos1);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[0]]->s_sprt, NULL);
	}
	if (icm->inventory[1] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[1]]->s_sprt,
		pos2);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[1]]->s_sprt, NULL);
	}
	display_inventory2(window, icm);
	display_inventory3(window, icm);
	display_inventory4(window, icm);
	display_inventory5(window, icm);
	display_inventory6(window, icm);
}

void display_inventory2(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos3 = {325, 375};
	sfVector2f pos4 = {435, 375};

	if (icm->inventory[2] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[2]]->s_sprt,
		pos3);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[2]]->s_sprt, NULL);
	}
	if (icm->inventory[3] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[3]]->s_sprt,
		pos4);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[3]]->s_sprt, NULL);
	}
}

void display_inventory3(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos5 = {110, 483};
	sfVector2f pos6 = {215, 483};

	if (icm->inventory[4] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[4]]->s_sprt,
		pos5);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[4]]->s_sprt, NULL);
	}
	if (icm->inventory[5] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[5]]->s_sprt,
		pos6);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[5]]->s_sprt, NULL);
	}
}
