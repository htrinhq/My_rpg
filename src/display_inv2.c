/*
** EPITECH PROJECT, 2017
** display_inv.c
** File description:
** desc
*/

#include "rpg.h"

void display_inventory4(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos7 = {325, 483};
	sfVector2f pos8 = {435, 483};

	if (icm->inventory[6] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[6]]->s_sprt,
		pos7);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[6]]->s_sprt, NULL);
	}
	if (icm->inventory[7] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[7]]->s_sprt,
		pos8);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[7]]->s_sprt, NULL);
	}
}

void display_inventory5(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos9 = {110, 592};
	sfVector2f pos10 = {215, 592};

	if (icm->inventory[8] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[8]]->s_sprt,
		pos9);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[8]]->s_sprt, NULL);
	}
	if (icm->inventory[9] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[9]]->s_sprt,
		pos10);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[9]]->s_sprt, NULL);
	}
}

void display_inventory6(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos11 = {325, 592};
	sfVector2f pos12 = {435, 592};

	if (icm->inventory[10] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[10]]->s_sprt,
		pos11);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[10]]->s_sprt, NULL);
	}
	if (icm->inventory[11] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[11]]->s_sprt,
		pos12);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[11]]->s_sprt, NULL);
	}
	display_inventory7(window, icm);
	display_inventory8(window, icm);
}

void display_inventory7(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos13 = {110, 703};
	sfVector2f pos14 = {215, 703};

	if (icm->inventory[12] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[12]]->s_sprt,
		pos13);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[12]]->s_sprt, NULL);
	}
	if (icm->inventory[13] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[13]]->s_sprt,
		pos14);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[13]]->s_sprt, NULL);
	}
}

void display_inventory8(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos15 = {325, 703};
	sfVector2f pos16 = {435, 703};

	if (icm->inventory[14] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[14]]->s_sprt,
		pos15);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[14]]->s_sprt, NULL);
	}
	if (icm->inventory[15] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[15]]->s_sprt,
		pos16);
		sfRenderWindow_drawSprite(window,
		icm->s_obj[icm->inventory[15]]->s_sprt, NULL);
	}
}
