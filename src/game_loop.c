/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "rpg.h"

void display_sprites_game(sfRenderWindow *window, sprite_t **sprite)
{
	sfRenderWindow_drawSprite(window, sprite[0]->s_sprt, NULL);
	display_npc(window, sprite[0]->r_sprt, sprite[1]);
	sfRenderWindow_drawSprite(window, sprite[1]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[3]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[4]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[7]->s_sprt, NULL);
}

void set_sprite_16(sprite_t **sprite)
{
	sprite[16]->v_sprt.x = 198;
	sprite[16]->v_sprt.y = 42;
	sprite[16]->v_sprt.x = sprite[16]->v_sprt.x * 9.8- sprite[0]->r_sprt.left;
	sprite[16]->v_sprt.y = sprite[16]->v_sprt.y * 18.5 - sprite[0]->r_sprt.top;
	sfSprite_setPosition(sprite[16]->s_sprt, sprite[16]->v_sprt);
}

void game_loop(sfRenderWindow *window, sprite_t **sprite, icm_t *icm,
	plstat_t *stat)
{
	sfEvent event;

	/*sfRenderWindow_drawSprite(window, sprite[0]->s_sprt, NULL);
	display_npc(window, sprite[0]->r_sprt, sprite[1]);
	sfRenderWindow_drawSprite(window, sprite[1]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[3]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[4]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[7]->s_sprt, NULL);*/
	display_sprites_game(window, sprite);
	fight(stat, sprite, window);
	if (sprite[16]->o_sprt > 0)
		sfRenderWindow_drawSprite(window, sprite[16]->s_sprt, NULL);
	/*sprite[16]->v_sprt.x = 198;
	sprite[16]->v_sprt.y = 42;
	sprite[16]->v_sprt.x = sprite[16]->v_sprt.x * 9.8- sprite[0]->r_sprt.left;
	sprite[16]->v_sprt.y = sprite[16]->v_sprt.y * 18.5 - sprite[0]->r_sprt.top;
	sfSprite_setPosition(sprite[16]->s_sprt, sprite[16]->v_sprt);*/
	set_sprite_16(sprite);
	if (sprite[2]->o_sprt == 1) {
		sfRenderWindow_drawSprite(window, sprite[2]->s_sprt, NULL);
		display_stat(sprite, window, stat);
		display_inventory(window, icm);
	}
	if (sprite[8]->o_sprt == 1)
		sfRenderWindow_drawSprite(window, sprite[8]->s_sprt, NULL);
	if (sprite[14]->o_sprt == 1 && sprite[8]->o_sprt == 1) {
		sfRenderWindow_drawSprite(window, sprite[14]->s_sprt, NULL);
		display_chest(sprite[14]->v_sprt.x, sprite[14]->v_sprt.y, icm, window);
		display_inventory(window, icm);
	}
	day_time(window, sprite);
	game_event(window, event, sprite, icm);
	sfRenderWindow_display(window);
}
