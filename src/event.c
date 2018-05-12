/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event functions
*/

#include "rpg.h"

void modif_sprite(sprite_t **sprite, sfEvent event)
{
	if (event.type != sfEvtMouseButtonPressed)
		return;
	if (event.mouseButton.x >= 1480 &&
		event.mouseButton.x <= 1680 &&
		event.mouseButton.y >= 690 &&
		event.mouseButton.y <= 890)
		sprite[5]->o_sprt = 5;
}

void inside_menu_while(sfEvent event, sfRenderWindow *window,
text_t **text, sprite_t **sprite)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (sfKeyboard_isKeyPressed(sfKeyUp) && sprite[5]->o_sprt == 0)
		text = move_cursos_up(text);
	if (sfKeyboard_isKeyPressed(sfKeyDown) && sprite[5]->o_sprt == 0)
		text = move_cursos_down(text);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sprite[5]->o_sprt == 0 &&
		text[2]->pos.y == 375 + (3 * 77))
		sfRenderWindow_close(window);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sprite[5]->o_sprt == 0 &&
		text[2]->pos.y == 375 + 77)
		sprite[5]->o_sprt = 1;
	if (sfKeyboard_isKeyPressed(sfKeyS))
		sprite[5]->o_sprt = 5;
	modif_sprite(sprite, event);
}

text_t **menu_event(sfRenderWindow *window, sfEvent event, text_t **text,
sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event))
		inside_menu_while(event, window, text, sprite);
	return (text);
}

void dlc_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type != sfEvtKeyPressed)
			return;
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sprite[5]->o_sprt = 0;
	}
}

void pause_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type != sfEvtKeyPressed)
			return;
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyP) ||
			sfKeyboard_isKeyPressed(sfKeyEscape) ||
			sfKeyboard_isKeyPressed(sfKeyR))
			sprite[5]->o_sprt = 1;
	}
}
