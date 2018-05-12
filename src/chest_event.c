/*
** EPITECH PROJECT, 2017
** chest_event.c
** File description:
** event for chest manipulations
*/

#include "rpg.h"

void change_ch_inv(icm_t *icm, int id)
{
	if (icm->chests[icm->ch]->inside[id] != -1) {
		if (add_inventory(icm->chests[icm->ch]->inside[id], icm))
			icm->chests[icm->ch]->inside[id] = -1;
	} else
		return;
}

void change_inv_ch(icm_t *icm, int id)
{
	if (icm->inventory[id] != -1) {
		add_chest(icm->inventory[id], icm, icm->ch);
		icm->inventory[id] = -1;
	} else
		return;
}
