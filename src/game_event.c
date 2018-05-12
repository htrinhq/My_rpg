/*
** EPITECH PROJECT, 2017
** game_event.c
** File description:
** game event functions
*/

#include "rpg.h"

void get_move(icm_t *icm, sprite_t **sprite, int pst)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		pst += 1;
	if (sfKeyboard_isKeyPressed(sfKeyS))
		pst += 2;
	if (sfKeyboard_isKeyPressed(sfKeyQ))
		pst += 4;
	if (sfKeyboard_isKeyPressed(sfKeyD))
		pst += 8;
	if (pst != 0) {
		move_player(sprite, icm, pst);
		particules(window, 975, 630, 1);
	}
}

void mouse_button(sprite_t **sprite, sfEvent event, sfRenderWindow *window,
icm_t *icm)
{
	if (sprite[2]->o_sprt == 1 && (event.mouseButton.x >= 1332 &&
		event.mouseButton.x <= (1332 + 250)) &&
		(event.mouseButton.y >= 747 &&
		event.mouseButton.y <= (747 + 95)) &&
		sfMouse_isButtonPressed(sfMouseLeft))
		sfRenderWindow_destroy(window);
	if (sprite[2]->o_sprt == 1 && (event.mouseButton.x >= 1605 &&
	event.mouseButton.x <= (1605 + 250)) &&
	(event.mouseButton.y >= 747 &&
	event.mouseButton.y <= (747 + 95)) &&
	sfMouse_isButtonPressed(sfMouseLeft)) {
		sprite[1]->o_sprt = 0;
		sprite[5]->o_sprt = 0;
	}
	if (sprite[14]->o_sprt == 1) {
		if (sfMouse_isButtonPressed(sfMouseLeft))
			change_chest(event, icm);
	}
}

void game_event2(sfRenderWindow *window, sfEvent event,
sprite_t **sprite, icm_t *icm)
{
	int pst = 0;
	mouse_button(sprite, event, window, icm);
	if (event.type != sfEvtKeyPressed)
		return;
	if (sprite[14]->o_sprt == 0)
		get_move(icm, sprite, pst);
	if (sfKeyboard_isKeyPressed(sfKeyP))
		sprite[5]->o_sprt = 3;
	if (sfKeyboard_isKeyPressed(sfKeyI) && sprite[14]->o_sprt == 0)
		sprite[2]->o_sprt = (sprite[2]->o_sprt == 0) ? 1 : 0;
	if (sfKeyboard_isKeyPressed(sfKeyE) && sprite[8]->o_sprt == 1 &&
		sprite[2]->o_sprt == 0)
		sprite[14]->o_sprt = (sprite[14]->o_sprt == 0) ? 1 : 0;
}

sprite_t **game_event(sfRenderWindow *window, sfEvent event,
sprite_t **sprite, icm_t *icm)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		game_event2(window, event, sprite, icm);
	}
	return (sprite);
}
