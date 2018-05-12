/*
** EPITECH PROJECT, 2017
** initialize_sprite.c
** File description:
** sprite creation functions
*/

#include "rpg.h"

void initialize_sprite2(sprite_t **sprite, plstat_t *stat)
{
	sfVector2f scale = {0.5, 0.5};
	sfVector2f scale2 = {2, 2};
	sfVector2f scale3 = {5, 5};
	int level = (stat->xp % 100) * 8 / 100;

	sprite[1]->r_sprt.top = 10;
	sprite[1]->r_sprt.left = 70;
	sprite[1]->r_sprt.width = 136;
	sprite[1]->r_sprt.height = 183;
	sprite[7]->r_sprt.top = 20 * stat->life;
	sprite[7]->r_sprt.left = 0;
	sprite[7]->r_sprt.width = 100;
	sprite[7]->r_sprt.height = 20;
	sprite[9]->r_sprt.top = 20 * stat->force;
	sprite[9]->r_sprt.left = 0;
	sprite[9]->r_sprt.width = 100;
	sprite[9]->r_sprt.height = 20;
	sprite[10]->r_sprt.top = 20 * stat->inteligence;
	sprite[10]->r_sprt.left = 0;
	sprite[10]->r_sprt.width = 100;
	sprite[10]->r_sprt.height = 20;
	sprite[11]->r_sprt.top = 20 * stat->speed;
	sprite[11]->r_sprt.left = 0;
	sprite[11]->r_sprt.width = 100;
	sprite[11]->r_sprt.height = 20;
	sprite[12]->r_sprt.top = 20 * level;
	sprite[12]->r_sprt.left = 0;
	sprite[12]->r_sprt.width = 100;
	sprite[12]->r_sprt.height = 20;
	sprite[16]->r_sprt.top = 10;
	sprite[16]->r_sprt.left = 70;
	sprite[16]->r_sprt.width = 136;
	sprite[16]->r_sprt.height = 183;
	sprite[16]->v_sprt.x = 198;
	sprite[16]->v_sprt.y = 42;
	sprite[7]->v_sprt.x = 40;
	sprite[7]->v_sprt.y = 960;
	sprite[1]->v_sprt.x = 960;
	sprite[1]->v_sprt.y = 540;
	sprite[4]->v_sprt.x = 225 / 2 - 6;
	sprite[4]->v_sprt.y = 213 / 2 - 15;
	sprite[8]->v_sprt.x = 960;
	sprite[8]->v_sprt.y = 440;
	sprite[9]->v_sprt.x = 700;
	sprite[9]->v_sprt.y = 350;
	sprite[10]->v_sprt.x = 700;
	sprite[10]->v_sprt.y = 450;
	sprite[11]->v_sprt.x = 700;
	sprite[11]->v_sprt.y = 550;
	sprite[12]->v_sprt.x = 700;
	sprite[12]->v_sprt.y = 650;
	sprite[13]->v_sprt.x = 730;
	sprite[13]->v_sprt.y = 650;
	sprite[1]->o_sprt = 0;
	sprite[2]->o_sprt = 0;
	sprite[5]->o_sprt = 0;
	sprite[8]->o_sprt = 0;
	sprite[9]->o_sprt = 0;
	sprite[14]->o_sprt = 0;
	sprite[16]->o_sprt = 8;
	sprite[19]->o_sprt = 0;
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	sfSprite_setTextureRect(sprite[7]->s_sprt, sprite[7]->r_sprt);
	sfSprite_setTextureRect(sprite[9]->s_sprt, sprite[9]->r_sprt);
	sfSprite_setTextureRect(sprite[10]->s_sprt, sprite[10]->r_sprt);
	sfSprite_setTextureRect(sprite[11]->s_sprt, sprite[11]->r_sprt);
	sfSprite_setTextureRect(sprite[12]->s_sprt, sprite[12]->r_sprt);
	sfSprite_setTextureRect(sprite[16]->s_sprt, sprite[16]->r_sprt);
	sfSprite_setPosition(sprite[1]->s_sprt, sprite[1]->v_sprt);
	sfSprite_setPosition(sprite[7]->s_sprt, sprite[7]->v_sprt);
	sfSprite_setPosition(sprite[8]->s_sprt, sprite[8]->v_sprt);
	sfSprite_setPosition(sprite[9]->s_sprt, sprite[9]->v_sprt);
	sfSprite_setPosition(sprite[10]->s_sprt, sprite[10]->v_sprt);
	sfSprite_setPosition(sprite[11]->s_sprt, sprite[11]->v_sprt);
	sfSprite_setPosition(sprite[12]->s_sprt, sprite[12]->v_sprt);
	sfSprite_setPosition(sprite[16]->s_sprt, sprite[16]->v_sprt);
	sfSprite_setScale(sprite[1]->s_sprt, scale);
	sfSprite_setScale(sprite[7]->s_sprt, scale2);
	sfSprite_setScale(sprite[8]->s_sprt, scale2);
	sfSprite_setScale(sprite[9]->s_sprt, scale3);
	sfSprite_setScale(sprite[10]->s_sprt, scale3);
	sfSprite_setScale(sprite[11]->s_sprt, scale3);
	sfSprite_setScale(sprite[12]->s_sprt, scale3);
	sfSprite_setScale(sprite[16]->s_sprt, scale);
	sprite[13]->text = sfText_create();
	sprite[13]->font = sfFont_createFromFile("rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfText_setFont(sprite[13]->text, sprite[13]->font);
	sfText_setPosition(sprite[13]->text, sprite[13]->v_sprt);
	sfText_setCharacterSize(sprite[13]->text, 70);
}

sprite_t **initialize_sprite(sprite_t **sprite, plstat_t *stat)
{
	for (int i = 0; i < 20; i++)
		sprite[i] = malloc(sizeof(sprite_t) * 5);
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
	sprite[1] = create_sprite(sprite[1], "rsrc/pictures/p1.png");
	sprite[0] = create_sprite(sprite[0], "rsrc/pictures/map.png");
	sprite[0]->clock = sfClock_create();
	sprite[1]->clock = sfClock_create();
	sprite[0]->r_sprt.top = 1480;
	sprite[0]->r_sprt.left = 1260;
	sprite[0]->r_sprt.width = 1920;
	sprite[0]->r_sprt.height = 1080;
	sprite[0]->text = sfText_create();
	sprite[0]->font = sfFont_createFromFile("./rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfText_setFont(sprite[0]->text, sprite[0]->font);
	sfText_setCharacterSize(sprite[0]->text, 90);
	sfText_setColor(sprite[0]->text, sfColor_fromRGB(255, 255, 255));
	sfText_setPosition(sprite[0]->text, (sfVector2f){880, 0});
	initialize_sprite2(sprite, stat);
	return (sprite);
}
