/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rgp
*/

#include "rpg.h"

void day_time(sfRenderWindow *wd)
{
	text_t text;

	text.font = sfFont_createFromFile("./rsrc/fonts/copyfonts.com_algol-ix.ttf");
	text.text = sfText_create();
	text.pos.x = 550;
	text.pos.y = 125;
	printf("%s\n", my_int_to_str(game_clock()));
	sfText_setString(text.text, my_int_to_str(game_clock()));
	sfRenderWindow_drawText(wd, text.text, NULL);
}
