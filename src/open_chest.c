/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** open_chest
*/

#include "rpg.h"

int detect_chest(int x, int y, sprite_t **sprite)
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
	(x > 217 && x < 227 && y > 312 && y < 332))
	    sprite[8]->o_sprt = 1;
	else
		    sprite[8]->o_sprt = 0;
	    return (1);
	    }
