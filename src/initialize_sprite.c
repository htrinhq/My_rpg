/*
** EPITECH PROJECT, 2017
** initialize_sprite.c
** File description:
** sprite creation functions
*/

#include "rpg.h"

void initialize_sprite2(sprite_t **sprite, plstat_t *stat)
{
	int level = (stat->xp % 100) * 8 / 100;

	set_rect(sprite, stat);
	set_rect_2(sprite, stat, level);
	set_rect_3(sprite);
	set_o_sprt(sprite);
	set_texture_rect(sprite);
	set_position(sprite);
	set_scale(sprite);
	sprite[13]->text = sfText_create();
	sprite[13]->font = sfFont_createFromFile(
	"rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfText_setFont(sprite[13]->text, sprite[13]->font);
	sfText_setPosition(sprite[13]->text, sprite[13]->v_sprt);
	sfText_setCharacterSize(sprite[13]->text, 70);
}

void malloc_sprite(sprite_t **sprite)
{
	sprite[21] = create_sprite(sprite[21], "rsrc/pictures/gardian.png");
	sprite[20] = create_sprite(sprite[20], "rsrc/pictures/keeper.png");
	sprite[19] = create_sprite(sprite[19], "rsrc/pictures/begin.png");
	sprite[18] = create_sprite(sprite[18], "rsrc/pictures/die.png");
	sprite[17] = create_sprite(sprite[17], "rsrc/pictures/win.png");
	sprite[16] = create_sprite(sprite[16], "rsrc/pictures/gardian.png");
	sprite[15] = create_sprite(sprite[15], "rsrc/pictures/timeout.png");
	sprite[14] = create_sprite(sprite[14], "rsrc/pictures/chest.png");
	sprite[13]->text = sfText_create();
	sprite[12] = create_sprite(sprite[12], "rsrc/pictures/level.png");
	sprite[11] = create_sprite(sprite[11], "rsrc/pictures/speed.png");
	sprite[10] = create_sprite(sprite[10], "rsrc/pictures/inteligence.png");
	sprite[9] = create_sprite(sprite[9], "rsrc/pictures/force.png");
	sprite[8] = create_sprite(sprite[8], "rsrc/pictures/openchest.png");
	sprite[7] = create_sprite(sprite[7], "rsrc/pictures/life.png");
	sprite[6] = create_sprite(sprite[6], "rsrc/pictures/dlc.png");
	sprite[5] = create_sprite(sprite[5], "rsrc/pictures/pause.png");
	sprite[4] = create_sprite(sprite[4], "rsrc/pictures/minimap_perso.png");
	sprite[3] = create_sprite(sprite[3], "rsrc/pictures/minimap.png");
	sprite[2] = create_sprite(sprite[2], "rsrc/pictures/inventory.png");
}

void clock_create(sprite_t **sprite)
{
	sprite[1] = create_sprite(sprite[1], "rsrc/pictures/p1.png");
	sprite[0] = create_sprite(sprite[0], "rsrc/pictures/map.png");
	sprite[0]->clock = sfClock_create();
	sprite[1]->clock = sfClock_create();
	sprite[2]->clock = sfClock_create();
	sprite[3]->clock = sfClock_create();
	sprite[0]->r_sprt.top = 1480;
	sprite[0]->r_sprt.left = 1260;
	sprite[0]->r_sprt.width = 1920;
	sprite[0]->r_sprt.height = 1080;
	sprite[0]->text = sfText_create();
	sprite[0]->font = sfFont_createFromFile(
	"./rsrc/fonts/copyfonts.com_algol-ix.ttf");
}

sprite_t **initialize_sprite(sprite_t **sprite, plstat_t *stat)
{
	for (int i = 0; i < 22; i++)
		sprite[i] = malloc(sizeof(sprite_t) * 5);
	malloc_sprite(sprite);
	clock_create(sprite);
	sfText_setFont(sprite[0]->text, sprite[0]->font);
	sfText_setCharacterSize(sprite[0]->text, 90);
	sfText_setColor(sprite[0]->text, sfColor_fromRGB(255, 255, 255));
	sfText_setPosition(sprite[0]->text, (sfVector2f){880, 0});
	initialize_sprite2(sprite, stat);
	return (sprite);
}
