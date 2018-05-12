/*
** EPITECH PROJECT, 2017
** move_player.c
** File description:
** move player and cursor functions
*/

#include "rpg.h"

text_t **move_cursos_down(text_t **text)
{
	if (text[2]->pos.y == 375 + (3 * 77))
		text[2]->pos.y = 375;
	else
		text[2]->pos.y += 77;
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}

text_t **move_cursos_up(text_t **text)
{
	if (text[2]->pos.y == 375)
		text[2]->pos.y = 375 + (3 * 77);
	else
		text[2]->pos.y -= 77;
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}

sprite_t **player_animation(sprite_t **sprite, int x, int y)
{
	if (game_clock() > 0.46)
		sprite[1]->r_sprt.top += 320;
	if (sprite[1]->r_sprt.top == 970)
		sprite[1]->r_sprt.top = 10;
	sprite[4]->v_sprt.x = y / 2 - 6;
	sprite[4]->v_sprt.y = x / 2 - 15;
	sfSprite_setPosition(sprite[4]->s_sprt, sprite[4]->v_sprt);
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	return (sprite);
}

sprite_t **move_player(sprite_t **sprite, icm_t *icm, int pst)
{
	int y =  (sprite[0]->r_sprt.left - 1260) / 10 + 225;
	int x = (sprite[0]->r_sprt.top - 1480) / 10 + 213;

	detect_chest(x, y, sprite, icm);
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
	return (player_animation(sprite, x, y));
}
