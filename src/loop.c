/*
** EPITECH PROJECT, 2017
** loop.c
** File description:
** loop functions
*/

#include "rpg.h"

void first_if_menuloop(sfRenderWindow *window, sprite_t *bg, text_t **text)
{
	sfRenderWindow_drawSprite(window, bg->s_sprt, NULL);
	disp_text(window, text);
}

void menu_loop(sfRenderWindow *window, icm_t *icm)
{
	text_t **text = malloc(sizeof(text_t *) * 5);
	sprite_t *bg = malloc(sizeof(sprite_t));
	sfEvent event;
	sprite_t **sprite = malloc(sizeof(sprite_t *) * 17);
	plstat_t *stat = malloc(sizeof(plstat_t));

	create_icm_stat_text(stat, sprite, icm, text);
	bg = create_sprite(bg, "rsrc/pictures/bg.png");
	while (sfRenderWindow_isOpen(window)) {
		if (sprite[5]->o_sprt == 0) {
			text = menu_event(window, event, text, sprite);
			first_if_menuloop(window, bg, text);
			sfRenderWindow_display(window);
		} else if (sprite[5]->o_sprt == 3) {
			pause_loop(window, sprite);
		} else if (sprite[5]->o_sprt == 5) {
			dlc_loop(window, sprite);
		} else
			game_loop(window, sprite, icm, stat);
	}
}

void dlc_loop(sfRenderWindow *window, sprite_t **sprite)
{
	sfEvent event;

	dlc_event(window, event, sprite);
	sfRenderWindow_drawSprite(window, sprite[6]->s_sprt, NULL);
	sfRenderWindow_display(window);
}

void pause_loop(sfRenderWindow *window, sprite_t **sprite)
{
	sfEvent event;

	pause_event(window, event, sprite);
	sfRenderWindow_drawSprite(window, sprite[5]->s_sprt, NULL);
	sfRenderWindow_display(window);
}
