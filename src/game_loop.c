/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "rpg.h"

void set_sprite_16(sprite_t **s)
{
	s[16]->v_sprt.x = 198;
	s[16]->v_sprt.y = 42;
	s[16]->v_sprt.x = s[16]->v_sprt.x * 9.8- s[0]->r_sprt.left;
	s[16]->v_sprt.y = s[16]->v_sprt.y * 18.5 - s[0]->r_sprt.top;
	sfSprite_setPosition(s[16]->s_sprt, s[16]->v_sprt);
}

void display_sprites_game(sfRenderWindow *window, sprite_t **sprite)
{
	sfRenderWindow_drawSprite(window, sprite[0]->s_sprt, NULL);
	display_npc(window, sprite[0]->r_sprt, sprite[1]);
	if (sprite[16]->o_sprt > 0)
		sfRenderWindow_drawSprite(window, sprite[16]->s_sprt, NULL);
	if (sprite[20]->o_sprt == 0)
		sfRenderWindow_drawSprite(window, sprite[1]->s_sprt, NULL);
	else
		sfRenderWindow_drawSprite(window, sprite[21]->s_sprt, NULL);
	set_sprite_16(sprite);
	sfRenderWindow_drawSprite(window, sprite[3]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[4]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[7]->s_sprt, NULL);
}

void fight_display(sfRenderWindow *window, sprite_t **sprite, icm_t *icm,
plstat_t *stat)
{
	display_sprites_game(window, sprite);
	stat->force = count_weapons(icm);
}

void end_game_loop(sfRenderWindow *window, sprite_t **sprite,
icm_t *icm, sfEvent event)
{
	day_time(window, sprite);
	game_event(window, event, sprite, icm);
	if (sprite[14]->o_sprt == 1 && sprite[8]->o_sprt == 1) {
		sfRenderWindow_drawSprite(window, sprite[14]->s_sprt, NULL);
		display_chest(sprite[14]->v_sprt.x, sprite[14]->v_sprt.y,
		icm, window);
		display_inventory(window, icm);
	}
}

void game_loop(sfRenderWindow *window, sprite_t **sprite, icm_t *icm,
plstat_t *stat)
{
	sfEvent event;

	fight_display(window, sprite, icm, stat);
	if (sprite[2]->o_sprt == 1) {
		sfRenderWindow_drawSprite(window, sprite[2]->s_sprt, NULL);
		display_stat(sprite, window, stat);
		display_inventory(window, icm);
	}
	if (sprite[8]->o_sprt == 1)
		sfRenderWindow_drawSprite(window, sprite[8]->s_sprt, NULL);
	if (sprite[8]->o_sprt == 2)
		sfRenderWindow_drawSprite(window, sprite[20]->s_sprt, NULL);
	end_game_loop(window, sprite, icm, event);
	fight(stat, sprite, window, icm);
}
