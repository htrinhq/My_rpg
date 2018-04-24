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

guard_t **get_guards(int bo, guard_t **guards)
{
	static guard_t **tab;

	if (bo == 1)
		tab = guards;
	return (tab);
}

npc_t **get_npc(int bo, npc_t **npc)
{
	static npc_t **tab;

	if (bo == 1)
		tab = npc;
	return (tab);
}