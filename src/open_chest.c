/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** open_chest
*/

#include "rpg.h"

int detect_chest(int x, int y, sprite_t **sprite)
{
	printf("%d, %d\n", x, y);
	if (x > 166 && x < 178 && y > 140 && y < 150)
		sprite[8]->o_sprt = 1;
	else
		sprite[8]->o_sprt = 0;
	return (1);
}
