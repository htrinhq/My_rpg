/*
** EPITECH PROJECT, 2018
** stat.c
** File description:
** stat.c
*/

#include "rpg.h"

void display_level(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	int int_level = stat->xp % 100;
	char *level = my_getnbr(int_level);
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfVector2f pos = {500, 500};

	sfText_setString(text, level);
	sfText_setFont(text, font);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window, text, NULL);
}

void display_force(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	sprite_t *force = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {200, 200};

	force = create_sprite(force, "rsrc/pictures/force.png");
	force->r_sprt.top = 20 * stat->force;
	force->r_sprt.left = 100;
	force->r_sprt.width = 100;
	force->r_sprt.height = 160;
	sfSprite_setPosition(force->s_sprt, pos);
	sfRenderWindow_drawSprite(window, force->s_sprt, NULL);
}

void display_inteligence(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	sprite_t *intel = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {200, 500};

	intel = create_sprite(intel, "rsrc/pictures/inteligence.png");
	intel->r_sprt.top = 20 * stat->inteligence;
	intel->r_sprt.left = 100;
	intel->r_sprt.width = 100;
	intel->r_sprt.height = 160;
	sfSprite_setPosition(intel->s_sprt, pos);
	sfRenderWindow_drawSprite(window, intel->s_sprt, NULL);
}

void display_speed(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	sprite_t *speed = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {200, 700};

	speed = create_sprite(speed, "rsrc/pictures/speed.png");
	speed->r_sprt.top = 20 * stat->speed;
	speed->r_sprt.left = 100;
	speed->r_sprt.width = 100;
	speed->r_sprt.height = 160;
	sfSprite_setPosition(speed->s_sprt, pos);
	sfRenderWindow_drawSprite(window, speed->s_sprt, NULL);
}
