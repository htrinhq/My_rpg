/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** open_chest
*/

#include "rpg.h"

int *create_inventory(int *inventory)
{
	int x = 0;

	for (x = 0; x < 16; x = x + 1)
		inventory[x] = -1;
	inventory[16] = -2;
	return (inventory);
}

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
	sfVector2f pos5 = {750, 550};
	sfVector2f pos6 = {855, 550};
	sfVector2f pos7 = {960, 550};
	sfVector2f pos8 = {1075, 550};

	if (chests->inside[0] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[0]]->s_sprt, pos1);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[0]]->s_sprt, NULL);
	}
	if (chests->inside[1] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[1]]->s_sprt, pos2);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[1]]->s_sprt, NULL);
	}
	if (chests->inside[2] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[2]]->s_sprt, pos3);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[2]]->s_sprt, NULL);
	}
	if (chests->inside[3] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[3]]->s_sprt, pos4);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[3]]->s_sprt, NULL);
	}
	if (chests->inside[4] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[4]]->s_sprt, pos5);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[4]]->s_sprt, NULL);
	}
	if (chests->inside[5] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[5]]->s_sprt, pos6);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[5]]->s_sprt, NULL);
	}
	if (chests->inside[6] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[6]]->s_sprt, pos7);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[6]]->s_sprt, NULL);
	}
	if (chests->inside[7] != -1) {
		sfSprite_setPosition(icm->s_obj[chests->inside[7]]->s_sprt, pos8);
		sfRenderWindow_drawSprite(window, icm->s_obj[chests->inside[7]]->s_sprt, NULL);
	}
}

void display_inventory(sfRenderWindow *window, icm_t *icm)
{
	sfVector2f pos1 = {110, 375};
	sfVector2f pos2 = {215, 375};
	sfVector2f pos3 = {325, 375};
	sfVector2f pos4 = {435, 375};
	sfVector2f pos5 = {110, 483};
	sfVector2f pos6 = {215, 483};
	sfVector2f pos7 = {325, 483};
	sfVector2f pos8 = {435, 483};
	sfVector2f pos9 = {110, 592};
	sfVector2f pos10 = {215, 592};
	sfVector2f pos11 = {325, 592};
	sfVector2f pos12 = {435, 592};
	sfVector2f pos13 = {110, 703};
	sfVector2f pos14 = {215, 703};
	sfVector2f pos15 = {325, 703};
	sfVector2f pos16 = {435, 703};

	if (icm->inventory[0] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[0]]->s_sprt, pos1);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[0]]->s_sprt, NULL);
	}
	if (icm->inventory[1] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[1]]->s_sprt, pos2);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[1]]->s_sprt, NULL);
	}
	if (icm->inventory[2] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[2]]->s_sprt, pos3);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[2]]->s_sprt, NULL);
	}
	if (icm->inventory[3] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[3]]->s_sprt, pos4);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[3]]->s_sprt, NULL);
	}
	if (icm->inventory[4] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[4]]->s_sprt, pos5);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[4]]->s_sprt, NULL);
	}
	if (icm->inventory[5] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[5]]->s_sprt, pos6);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[5]]->s_sprt, NULL);
	}
	if (icm->inventory[6] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[6]]->s_sprt, pos7);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[6]]->s_sprt, NULL);
	}
	if (icm->inventory[7] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[7]]->s_sprt, pos8);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[7]]->s_sprt, NULL);
	}
	if (icm->inventory[8] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[8]]->s_sprt, pos9);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[8]]->s_sprt, NULL);
	}
	if (icm->inventory[9] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[9]]->s_sprt, pos10);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[9]]->s_sprt, NULL);
	}
	if (icm->inventory[10] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[10]]->s_sprt, pos11);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[10]]->s_sprt, NULL);
	}
	if (icm->inventory[11] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[11]]->s_sprt, pos12);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[11]]->s_sprt, NULL);
	}
	if (icm->inventory[12] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[12]]->s_sprt, pos13);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[12]]->s_sprt, NULL);
	}
	if (icm->inventory[13] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[13]]->s_sprt, pos14);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[13]]->s_sprt, NULL);
	}
	if (icm->inventory[14] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[14]]->s_sprt, pos15);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[14]]->s_sprt, NULL);
	}
	if (icm->inventory[15] != -1) {
		sfSprite_setPosition(icm->s_obj[icm->inventory[15]]->s_sprt, pos16);
		sfRenderWindow_drawSprite(window, icm->s_obj[icm->inventory[15]]->s_sprt, NULL);
	}

}

void display_chest(int x, int y, icm_t *icm, sfRenderWindow *window)
{

	if (x > 166 && x < 176 && y > 140 && y < 150) {
		icm->ch = 0;
		display_inside(icm->chests[0], icm, window);
	}
	if (x > 166 && x < 176 && y > 110 && y < 120) {
		icm->ch = 1;
		display_inside(icm->chests[1], icm, window);
	}
	if (x > 217 && x < 227 && y > 110 && y < 120) {
		icm->ch = 2;
		display_inside(icm->chests[2], icm, window);
	}
	if (x > 217 && x < 227 && y > 140 && y < 150) {
		icm->ch = 3;
		display_inside(icm->chests[3], icm, window);
	}
	if (x > 217 && x < 227 && y > 170 && y < 180) {
		icm->ch = 4;
		display_inside(icm->chests[4], icm, window);
	}
	if (x > 217 && x < 227 && y > 200 && y < 210) {
		icm->ch = 5;
		display_inside(icm->chests[5], icm, window);
	}
	if (x > 217 && x < 227 && y > 231 && y < 241) {
		icm->ch = 6;
		display_inside(icm->chests[6], icm, window);
	}
	if (x > 217 && x < 227 && y > 261 && y < 271) {
		icm->ch = 7;
		display_inside(icm->chests[7], icm, window);
	}
	if (x > 217 && x < 227 && y > 292 && y < 302) {
		icm->ch = 8;
		display_inside(icm->chests[8], icm, window);
	}
	if (x > 217 && x < 227 && y > 312 && y < 332) {
		icm->ch = 9;
		display_inside(icm->chests[9], icm, window);
	}
}

int detect_chest(int x, int y, sprite_t **sprite)
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
			sprite[14]->v_sprt.x = x;
			sprite[14]->v_sprt.y = y;
			sprite[8]->o_sprt = 1;
	} else
		sprite[8]->o_sprt = 0;
	return (1);
}
