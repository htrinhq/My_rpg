/*
** EPITECH PROJECT, 2018
** stock_var.c
** File description:
** stock_var.c
*/

#include "rpg.h"

sprite_t **get_sprite(int bo, sprite_t **sprite)
{
	static sprite_t **tab;

	if (bo == 1)
		tab = sprite;
	return (tab);
}