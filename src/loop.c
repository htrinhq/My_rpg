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

void launch_game(sfRenderWindow *window, sprite_t **sprite,
		icm_t *icm, plstat_t *stat)
{
	if (sprite[17]->o_sprt == 0 && (int)sfTime_asSeconds(
	sfClock_getElapsedTime(sprite[3]->clock)) >= 5)
		sprite[17]->o_sprt = 3;
	if ((int)sfTime_asSeconds(
	sfClock_getElapsedTime(sprite[3]->clock)) == 6)
		sfRenderWindow_close(window);
	if (sprite[17]->o_sprt == 0)
		sfRenderWindow_drawSprite(window, sprite[19]->s_sprt, NULL);
	if (sprite[17]->o_sprt == 1)
		sfRenderWindow_drawSprite(window, sprite[18]->s_sprt, NULL);
	if (sprite[17]->o_sprt == 2)
		sfRenderWindow_drawSprite(window, sprite[17]->s_sprt, NULL);
	if (sprite[17]->o_sprt == 3) {
		sfClock_restart(sprite[3]->clock);
		game_loop(window, sprite, icm, stat);
	}
	sfRenderWindow_display(window);
}

void menu_loop(sfRenderWindow *window, icm_t *icm)
{
	text_t **text = malloc(sizeof(text_t *) * 5);
	sprite_t *bg = malloc(sizeof(sprite_t));
	sfEvent event;
	sprite_t **sprite = malloc(sizeof(sprite_t *) * 23);
	plstat_t *stat = malloc(sizeof(plstat_t));

	create_icm_stat_text(stat, sprite, icm, text);
	bg = create_sprite(bg, "rsrc/pictures/bg.png");
	while (sfRenderWindow_isOpen(window)) {
		if (sprite[5]->o_sprt == 0) {
			text = menu_event(window, event, text, sprite);
			first_if_menuloop(window, bg, text);
			sfRenderWindow_display(window);
			continue;
		}
		if (sprite[5]->o_sprt == 3) {
			pause_loop(window, sprite);
		} else if (sprite[5]->o_sprt == 5) {
			dlc_loop(window, sprite);
		} else
			launch_game(window, sprite, icm, stat);
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
