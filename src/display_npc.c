/*
** EPITECH PROJECT, 2018
** display_npc.c
** File description:
** display_npc.c
*/

#include "rpg.h"

void display_npc3(sfRenderWindow *window, sfIntRect rect, npc_t *npc)
{
	sfVector2f scale = {0.5, 0.5};

	sfSprite_setTextureRect(npc->spr->s_sprt, npc->spr->r_sprt);
	sfSprite_setScale(npc->spr->s_sprt, scale);
	sfSprite_setPosition(npc->spr->s_sprt,
	get_real_pos(npc->map, npc->token, rect));
	sfRenderWindow_drawSprite(window, npc->spr->s_sprt, NULL);
}

void display_npc(sfRenderWindow *window, sfIntRect rect, sprite_t *sprite)
{
	npc_t **npc = get_npc(0, NULL);
	int i = 0;
	float a = sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));

	while (i < 7) {
		if (a > 0.03) {
			get_pos_routine(npc[i]->token, npc[i]->map);
			npc[i]->spr->r_sprt = npc_animation(
				npc[i]->spr->r_sprt);
			sfClock_restart(sprite->clock);
		}
		display_npc3(window, rect, npc[i]);
		i = i + 1;
	}
	display_guards(window, rect, a);
}

void display_guards(sfRenderWindow *window, sfIntRect rect, float a)
{
	guard_t **guard = get_guards(0, NULL);
	int i = 0;

	while (i < 3) {
		if (a > 0.03) {
			get_pos_routine(guard[i]->token, guard[i]->map);
			guard[i]->sprite->r_sprt = npc_animation(
				guard[i]->sprite->r_sprt);
		}
		display_guards2(window, rect, guard[i]);
		i = i + 1;
	}
}

void display_guards2(sfRenderWindow *window, sfIntRect rect, guard_t *guard)
{
	sfVector2f scale = {0.5, 0.5};

	sfSprite_setTextureRect(guard->sprite->s_sprt, guard->sprite->r_sprt);
	sfSprite_setScale(guard->sprite->s_sprt, scale);
	sfSprite_setPosition(guard->sprite->s_sprt,
	get_real_pos(guard->map, guard->token, rect));
	sfRenderWindow_drawSprite(window, guard->sprite->s_sprt, NULL);
}

sfIntRect npc_animation(sfIntRect rect)
{
	if (rect.top == 0) {
		rect.top = 320;
		return (rect);
	}
	if (rect.top == 320) {
		rect.top = 640;
		return (rect);
	}
	if (rect.top == 640) {
		rect.top = 0;
		return (rect);
	}
}