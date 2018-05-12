/*
** EPITECH PROJECT, 2017
** change_chest.c
** File description:
** change_chest functions
*/

#include "rpg.h"

void change_chest_fif(sfEvent event, icm_t *icm)
{
	if (event.mouseButton.x > 112 &&  event.mouseButton.x < 211 &&
		event.mouseButton.y > 703 && event.mouseButton.y < 803)
		change_inv_ch(icm, 12);
	if (event.mouseButton.x > 221 &&  event.mouseButton.x < 322 &&
		event.mouseButton.y > 703 && event.mouseButton.y < 803)
		change_inv_ch(icm, 13);
	if (event.mouseButton.x > 332 &&  event.mouseButton.x < 432 &&
		event.mouseButton.y > 703 && event.mouseButton.y < 803)
		change_inv_ch(icm, 14);
	if (event.mouseButton.x > 442 &&  event.mouseButton.x < 541 &&
		event.mouseButton.y > 703 && event.mouseButton.y < 803)
		change_inv_ch(icm, 15);
}

void change_chest_fth(sfEvent event, icm_t *icm)
{
	if (event.mouseButton.x > 332 &&  event.mouseButton.x < 432 &&
		event.mouseButton.y > 483 && event.mouseButton.y < 581)
		change_inv_ch(icm, 6);
	if (event.mouseButton.x > 442 &&  event.mouseButton.x < 541 &&
		event.mouseButton.y > 483 && event.mouseButton.y < 581)
		change_inv_ch(icm, 7);
	if (event.mouseButton.x > 112 &&  event.mouseButton.x < 211 &&
		event.mouseButton.y > 592 && event.mouseButton.y < 692)
		change_inv_ch(icm, 8);
	if (event.mouseButton.x > 221 &&  event.mouseButton.x < 322 &&
		event.mouseButton.y > 592 && event.mouseButton.y < 692)
		change_inv_ch(icm, 9);
	if (event.mouseButton.x > 332 &&  event.mouseButton.x < 432 &&
		event.mouseButton.y > 592 && event.mouseButton.y < 692)
		change_inv_ch(icm, 10);
	if (event.mouseButton.x > 442 &&  event.mouseButton.x < 541 &&
		event.mouseButton.y > 592 && event.mouseButton.y < 692)
		change_inv_ch(icm, 11);
	change_chest_fif(event, icm);
}

void change_chest_thr(sfEvent event, icm_t *icm)
{
	if (event.mouseButton.x > 112 &&  event.mouseButton.x < 211 &&
		event.mouseButton.y > 373 && event.mouseButton.y < 471)
		change_inv_ch(icm, 0);
	if (event.mouseButton.x > 221 &&  event.mouseButton.x < 322 &&
		event.mouseButton.y > 373 && event.mouseButton.y < 471)
		change_inv_ch(icm, 1);
	if (event.mouseButton.x > 332 &&  event.mouseButton.x < 432 &&
		event.mouseButton.y > 373 && event.mouseButton.y < 471)
		change_inv_ch(icm, 2);
	if (event.mouseButton.x > 442 &&  event.mouseButton.x < 541 &&
		event.mouseButton.y > 373 && event.mouseButton.y < 471)
		change_inv_ch(icm, 3);
	if (event.mouseButton.x > 112 &&  event.mouseButton.x < 211 &&
		event.mouseButton.y > 483 && event.mouseButton.y < 581)
		change_inv_ch(icm, 4);
	if (event.mouseButton.x > 221 &&  event.mouseButton.x < 322 &&
		event.mouseButton.y > 483 && event.mouseButton.y < 581)
		change_inv_ch(icm, 5);
	change_chest_fth(event, icm);
}

void change_chest_sec(sfEvent event, icm_t *icm)
{
	if (event.mouseButton.x > 747 &&  event.mouseButton.x < 846 &&
		event.mouseButton.y > 558 && event.mouseButton.y < 656)
		change_ch_inv(icm, 4);
	if (event.mouseButton.x > 857 &&  event.mouseButton.x < 955 &&
		event.mouseButton.y > 558 && event.mouseButton.y < 656)
		change_ch_inv(icm, 5);
	if (event.mouseButton.x > 966 &&  event.mouseButton.x < 1065 &&
		event.mouseButton.y > 558 && event.mouseButton.y < 656)
		change_ch_inv(icm, 6);
	if (event.mouseButton.x > 1077 &&  event.mouseButton.x < 1175 &&
		event.mouseButton.y > 558 && event.mouseButton.y < 656)
		change_ch_inv(icm, 7);
	change_chest_thr(event, icm);
}

void change_chest(sfEvent event, icm_t *icm)
{
	if (event.mouseButton.x > 747 &&  event.mouseButton.x < 846 &&
		event.mouseButton.y > 432 && event.mouseButton.y < 531)
		change_ch_inv(icm, 0);
	if (event.mouseButton.x > 857 &&  event.mouseButton.x < 955 &&
		event.mouseButton.y > 432 && event.mouseButton.y < 531)
		change_ch_inv(icm, 1);
	if (event.mouseButton.x > 966 &&  event.mouseButton.x < 1065 &&
		event.mouseButton.y > 432 && event.mouseButton.y < 531)
		change_ch_inv(icm, 2);
	if (event.mouseButton.x > 1077 &&  event.mouseButton.x < 1175 &&
		event.mouseButton.y > 432 && event.mouseButton.y < 531)
		change_ch_inv(icm, 3);
	change_chest_sec(event, icm);
}
