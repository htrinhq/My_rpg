/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** open_chest
*/

#include "rpg.h"

sprite_t **fill_obj_sprite(sprite_t **obj)
{
	sfVector2f scale = {0.15, 0.15};

	obj[0] = malloc(sizeof(sprite_t));
	obj[1] = malloc(sizeof(sprite_t));
	obj[2] = malloc(sizeof(sprite_t));
	obj[3] = malloc(sizeof(sprite_t));
	obj[4] = malloc(sizeof(sprite_t));
	obj[5] = malloc(sizeof(sprite_t));
	obj[6] = malloc(sizeof(sprite_t));
	obj[7] = malloc(sizeof(sprite_t));
	obj[8] = malloc(sizeof(sprite_t));
	obj[9] = malloc(sizeof(sprite_t));
	obj[10] = malloc(sizeof(sprite_t));
	obj[11] = malloc(sizeof(sprite_t));
	obj[12] = malloc(sizeof(sprite_t));
	obj[13] = malloc(sizeof(sprite_t));
	obj[14] = malloc(sizeof(sprite_t));
	obj[0] = create_sprite(obj[0], "rsrc/pictures/bear.png");
	sfSprite_setScale(obj[0]->s_sprt, scale);
	obj[1] = create_sprite(obj[1], "rsrc/pictures/book.png");
	sfSprite_setScale(obj[1]->s_sprt, scale);
	obj[2] = create_sprite(obj[2], "rsrc/pictures/chauss.png");
	sfSprite_setScale(obj[2]->s_sprt, scale);
	obj[3] = create_sprite(obj[3], "rsrc/pictures/fork.png");
	sfSprite_setScale(obj[3]->s_sprt, scale);
	obj[4] = create_sprite(obj[4], "rsrc/pictures/glass.png");
	sfSprite_setScale(obj[4]->s_sprt, scale);
	obj[5] = create_sprite(obj[5], "rsrc/pictures/key.png");
	sfSprite_setScale(obj[5]->s_sprt, scale);
	obj[6] = create_sprite(obj[6], "rsrc/pictures/knife.png");
	sfSprite_setScale(obj[6]->s_sprt, scale);
	obj[7] = create_sprite(obj[7], "rsrc/pictures/lime.png");
	sfSprite_setScale(obj[7]->s_sprt, scale);
	obj[8] = create_sprite(obj[8], "rsrc/pictures/phone.png");
	sfSprite_setScale(obj[8]->s_sprt, scale);
	obj[9] = create_sprite(obj[9], "rsrc/pictures/savon.png");
	sfSprite_setScale(obj[9]->s_sprt, scale);
	obj[10] = create_sprite(obj[10], "rsrc/pictures/scotch.png");
	sfSprite_setScale(obj[10]->s_sprt, scale);
	obj[11] = create_sprite(obj[11], "rsrc/pictures/screwdriver.png");
	sfSprite_setScale(obj[11]->s_sprt, scale);
	obj[12] = create_sprite(obj[12], "rsrc/pictures/shaver.png");
	sfSprite_setScale(obj[12]->s_sprt, scale);
	obj[13] = create_sprite(obj[13], "rsrc/pictures/toothpaste.png");
	sfSprite_setScale(obj[13]->s_sprt, scale);
	obj[14] = create_sprite(obj[14], "rsrc/pictures/wisky.png");
	sfSprite_setScale(obj[14]->s_sprt, scale);
	return (obj);
}

void display_inside(chest_t *chests, icm_t *icm, sfRenderWindow *window)
{
	sfVector2f pos1 = {750, 435};
	sfVector2f pos2 = {855, 435};
	sfVector2f pos3 = {960, 435};
	sfVector2f pos4 = {1075, 435};

	if (chests->inside[0] == -1)
		return;
	sfSprite_setPosition(icm->s_obj[chests->inside[0]]->s_sprt, pos1);
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[0]]->s_sprt, NULL);
	if (chests->inside[1] == -1)
		return;
	sfSprite_setPosition(icm->s_obj[chests->inside[1]]->s_sprt, pos2);
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[1]]->s_sprt, NULL);
	if (chests->inside[2] == -1)
		return;
	sfSprite_setPosition(icm->s_obj[chests->inside[2]]->s_sprt, pos3);
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[2]]->s_sprt, NULL);
	if (chests->inside[3] == -1)
		return;
	sfSprite_setPosition(icm->s_obj[chests->inside[3]]->s_sprt, pos4);
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[3]]->s_sprt, NULL);
	if (chests->inside[4] == -1)
		return;
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[4]]->s_sprt, NULL);
	if (chests->inside[5] == -1)
		return;
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[5]]->s_sprt, NULL);
	if (chests->inside[6] == -1)
		return;
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[6]]->s_sprt, NULL);
	if (chests->inside[7] == -1)
		return;
	sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[7]]->s_sprt, NULL);

}

void display_chest(int x, int y, icm_t *icm, sfRenderWindow *window)
{
	if (x > 166 && x < 176 && y > 140 && y < 150)
		display_inside(icm->chests[0], icm, window);
	if (x > 166 && x < 176 && y > 110 && y < 120)
		display_inside(icm->chests[1], icm, window);
	if (x > 217 && x < 227 && y > 110 && y < 120)
		display_inside(icm->chests[2], icm, window);
	if (x > 217 && x < 227 && y > 140 && y < 150)
		display_inside(icm->chests[3], icm, window);
	if (x > 217 && x < 227 && y > 170 && y < 180)
		display_inside(icm->chests[4], icm, window);
	if (x > 217 && x < 227 && y > 200 && y < 210)
		display_inside(icm->chests[5], icm, window);
	if (x > 217 && x < 227 && y > 231 && y < 241)
		display_inside(icm->chests[6], icm, window);
	if (x > 217 && x < 227 && y > 261 && y < 271)
		display_inside(icm->chests[7], icm, window);
	if (x > 217 && x < 227 && y > 292 && y < 302)
		display_inside(icm->chests[8], icm, window);
	if (x > 217 && x < 227 && y > 312 && y < 332)
		display_inside(icm->chests[9], icm, window);
}

int detect_chest(int x, int y, sprite_t **sprite, icm_t *icm)
{
	if ((x > 166 && x < 176 && y > 140 && y < 150) ||
	(x > 166 && x < 176 && y > 110 && y < 120) ||
	(x > 217 && x < 227 && y > 110 && y < 120) ||
	(x > 217 && x < 227 && y > 140 && y < 150) ||
	(x > 217 && x < 227 && y > 170 && y < 180) ||
	(x > 217 && x < 227 && y > 200 && y < 210) ||
	(x > 217 && x < 227 && y > 231 && y < 241) ||
	(x > 217 && x < 227 && y > 261 && y < 271) ||
	(x > 217 && x < 227 && y > 292 && y < 302) ||
	(x > 217 && x < 227 && y > 312 && y < 332)) {
			sprite[9]->v_sprt.x = x;
			sprite[9]->v_sprt.y = y;
			sprite[8]->o_sprt = 1;
	} else
		sprite[8]->o_sprt = 0;
	return (1);
}
