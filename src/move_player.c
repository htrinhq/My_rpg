/*
** EPITECH PROJECT, 2017
** move_player.c
** File description:
** move player and cursor functions
*/

#include "rpg.h"

sprite_t **player_animation(sprite_t **sprite, int x, int y)
{
	sprite[4]->v_sprt.x = y / 2 - 6;
	sprite[4]->v_sprt.y = x / 2 - 15;
	sfSprite_setPosition(sprite[4]->s_sprt, sprite[4]->v_sprt);
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	if (sprite[20]->o_sprt == 0) {
		if (game_clock() > 0.46)
			sprite[1]->r_sprt.top += 320;
		if (sprite[1]->r_sprt.top == 970)
			sprite[1]->r_sprt.top = 10;
		sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	} else {
		if (game_clock() > 0.46)
			sprite[21]->r_sprt.top += 320;
		if (sprite[21]->r_sprt.top == 970)
			sprite[21]->r_sprt.top = 10;
		sfSprite_setTextureRect(sprite[21]->s_sprt, sprite[21]->r_sprt);
	}
	return (sprite);
}

int got_key(icm_t *icm)
{
	int x = 0;

	for (x = 0; icm->inventory[x] != -2; x = x + 1)
		if (icm->inventory[x] == 5)
			return (1);
	return (0);
}

sprite_t **move_player_enter(sprite_t **sprite, icm_t *icm, int pst)
{
	int y =  (sprite[0]->r_sprt.left - 1260) / 10 + 225;
	int x = (sprite[0]->r_sprt.top - 1480) / 10 + 213;

	detect_chest(x, y, sprite);
	if ((pst == 1 ||pst == 3 ||pst == 5 || pst == 9) && x > 0
		&& icm->map_txt[x - 1][y] == 'E')
		sprite[0]->r_sprt.top -= 10;
	if ((pst == 2 ||pst == 6 ||pst == 10 || pst == 3) && x < 305
		&& icm->map_txt[x + 1][y] == 'E')
		sprite[0]->r_sprt.top += 10;
	if ((pst == 4 ||pst == 6 ||pst == 5 || pst == 12) && y > 0 &&
		icm->map_txt[x][y - 1] == 'E')
		sprite[0]->r_sprt.left -= 10;
	if ((pst == 8 ||pst == 10 ||pst == 9 || pst == 14) && y < 460 &&
		icm->map_txt[x][y + 1] == 'E')
		sprite[0]->r_sprt.left += 10;
	return (player_animation(sprite, x, y));
}

sprite_t **move_player_director(sprite_t **sprite, icm_t *icm, int pst)
{
	int y =  (sprite[0]->r_sprt.left - 1260) / 10 + 225;
	int x = (sprite[0]->r_sprt.top - 1480) / 10 + 213;

	detect_chest(x, y, sprite);
	if ((pst == 1 ||pst == 3 ||pst == 5 || pst == 9) && x > 0
		&& icm->map_txt[x - 1][y] == 'D')
		sprite[0]->r_sprt.top -= 10;
	if ((pst == 2 ||pst == 6 ||pst == 10 || pst == 3) && x < 305
		&& icm->map_txt[x + 1][y] == 'D')
		sprite[0]->r_sprt.top += 10;
	if ((pst == 4 ||pst == 6 ||pst == 5 || pst == 12) && y > 0 &&
		icm->map_txt[x][y - 1] == 'D')
		sprite[0]->r_sprt.left -= 10;
	if ((pst == 8 ||pst == 10 ||pst == 9 || pst == 14) && y < 460 &&
		icm->map_txt[x][y + 1] == 'D')
		sprite[0]->r_sprt.left += 10;
	return (player_animation(sprite, x, y));
}

sprite_t **move_player(sprite_t **sprite, icm_t *icm, int pst)
{
	int y =  (sprite[0]->r_sprt.left - 1260) / 10 + 225;
	int x = (sprite[0]->r_sprt.top - 1480) / 10 + 213;

	detect_chest(x, y, sprite);
	if ((pst == 1 ||pst == 3 ||pst == 5 || pst == 9) && x > 0
		&& icm->map_txt[x - 1][y] == ' ')
		sprite[0]->r_sprt.top -= 10;
	if ((pst == 2 ||pst == 6 ||pst == 10 || pst == 3) && x < 305
		&& icm->map_txt[x + 1][y] == ' ')
		sprite[0]->r_sprt.top += 10;
	if ((pst == 4 ||pst == 6 ||pst == 5 || pst == 12) && y > 0 &&
		icm->map_txt[x][y - 1] == ' ')
		sprite[0]->r_sprt.left -= 10;
	if ((pst == 8 ||pst == 10 ||pst == 9 || pst == 14) && y < 460 &&
		icm->map_txt[x][y + 1] == ' ')
		sprite[0]->r_sprt.left += 10;
	if (got_key(icm) == 1)
		move_player_director(sprite, icm, pst);
	if (sprite[20]->o_sprt == 1)
		move_player_enter(sprite, icm, pst);
	return (player_animation(sprite, x, y));
}
