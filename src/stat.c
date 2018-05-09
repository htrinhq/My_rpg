/*
** EPITECH PROJECT, 2018
** stat.c
** File description:
** stat.c
*/

#include "rpg.h"

char *my_itoa(int nbr)
{
	char *str = malloc(sizeof(char) * 2);

	str[0] = nbr + 48;
	str[1] = 0;
	return (str);
}

void display_stat(sprite_t **sprite, sfRenderWindow *window, plstat_t *stat)
{
	char *level = NULL;

	sfRenderWindow_drawSprite(window, sprite[9]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[10]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[11]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[12]->s_sprt, NULL);	
	if (stat->xp < 100)
		level = my_itoa(0);
	else
		level = my_itoa(stat->xp / 100);
//	sfText_setString(sprite[13]->text, level);
//	sfRenderWindow_drawText(window, sprite[13]->text, NULL);
}
