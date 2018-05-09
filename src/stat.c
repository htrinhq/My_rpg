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

void display_level2(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	char *level = NULL;
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfVector2f pos = {730, 650};

	if (stat->xp < 100)
		level = my_itoa(0);
	else
		level = my_itoa(stat->xp / 100);
	sfText_setString(text, level);
	sfText_setFont(text, font);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 70);
	sfRenderWindow_drawText(window, text, NULL);
}

void display_level(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	sprite_t *level = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {700, 650};
	sfVector2f scale = {5, 5};
	int lev = (stat->xp % 100) * 8 / 100;
	static int i = 0;

	level = create_sprite(level, "rsrc/pictures/level.png");
	level->r_sprt.top = 20 * lev;
	level->r_sprt.left = 0;
	level->r_sprt.width = 100;
	level->r_sprt.height = 20;
	sfSprite_setTextureRect(level->s_sprt, level->r_sprt);
	sfSprite_setPosition(level->s_sprt, pos);
	sfSprite_setScale(level->s_sprt, scale);
	sfRenderWindow_drawSprite(window, level->s_sprt, NULL);
	display_level2(stat, sprite, window);
}

void display_force(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	sprite_t *force = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {700, 350};
	sfVector2f scale = {5, 5};

	force = create_sprite(force, "rsrc/pictures/force.png");
	force->r_sprt.top = 20 * stat->force;
	force->r_sprt.left = 0;
	force->r_sprt.width = 100;
	force->r_sprt.height = 20;
	sfSprite_setTextureRect(force->s_sprt, force->r_sprt);
	sfSprite_setPosition(force->s_sprt, pos);
	sfSprite_setScale(force->s_sprt, scale);
	sfRenderWindow_drawSprite(window, force->s_sprt, NULL);
}

void display_inteligence(plstat_t *stat, sprite_t **sprite,
			sfRenderWindow *window)
{
	sprite_t *intel = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {700, 450};
	sfVector2f scale = {5, 5};

	intel = create_sprite(intel, "rsrc/pictures/inteligence.png");
	intel->r_sprt.top = 20 * stat->inteligence;
	intel->r_sprt.left = 0;
	intel->r_sprt.width = 100;
	intel->r_sprt.height = 20;
	sfSprite_setTextureRect(intel->s_sprt, intel->r_sprt);
	sfSprite_setPosition(intel->s_sprt, pos);
	sfSprite_setScale(intel->s_sprt, scale);
	sfRenderWindow_drawSprite(window, intel->s_sprt, NULL);
}

void display_speed(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	sprite_t *speed = malloc(sizeof(sprite_t) * 8);
	sfVector2f pos = {700, 550};
	sfVector2f scale = {5, 5};

	speed = create_sprite(speed, "rsrc/pictures/speed.png");
	speed->r_sprt.top = 20 * stat->speed;
	speed->r_sprt.left = 0;
	speed->r_sprt.width = 100;
	speed->r_sprt.height = 20;
	sfSprite_setTextureRect(speed->s_sprt, speed->r_sprt);
	sfSprite_setPosition(speed->s_sprt, pos);
	sfSprite_setScale(speed->s_sprt, scale);
	sfRenderWindow_drawSprite(window, speed->s_sprt, NULL);
}

void display_stat(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window)
{
	display_level(stat, sprite, window);
	display_force(stat, sprite, window);
	display_inteligence(stat, sprite, window);
	display_speed(stat, sprite, window);
}
