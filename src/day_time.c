/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rgp
*/

#include "rpg.h"


void set_time_2(int hour, int min, sprite_t **sprite)
{
	if (min == 0) {
		sfText_setString(sprite[0]->text, my_strcat(my_int_to_str(hour), 4,
				" : ", "0", "0"));
		return;
	}
	if (min < 10) {
		sfText_setString(sprite[0]->text, my_strcat(my_int_to_str(hour), 4,
				" : ", "0", my_int_to_str(min)));
		return;
	}
	sfText_setString(sprite[0]->text, my_strcat(my_int_to_str(hour), 3,
						    " : ", my_int_to_str(min)));
}

void set_time(int hour, int min, sprite_t **sprite)
{
	if (hour == 0 && min == 0) {
		sfText_setString(sprite[0]->text, my_strcat("0", 3,
							" : ", "00"));
		return;
	}
	if (hour == 0 && min < 10) {
		sfText_setString(sprite[0]->text, my_strcat("0", 4,
				" : ", "0", my_int_to_str(min)));
		return;
	}
	if (hour == 0) {
		sfText_setString(sprite[0]->text, my_strcat("0", 3,
				" : ", my_int_to_str(min)));
		return;
	}
	set_time_2(hour, min, sprite);
}

void day_event(sfRenderWindow *wd, sprite_t **sprite, int hour, int min)
{
	static int mem = 0;

	if (hour >= 18 && min % 2 == 0)
		sfText_setString(sprite[0]->text, "!!! GO TO SLEEP !!!");
	if (hour >= 19 && (sprite[0]->r_sprt.top < 1390 || sprite[0]->r_sprt.top > 1690) && (sprite[0]->r_sprt.left < 1150 || sprite[0]->r_sprt.left > 1420)) {
		mem = min;
		sprite[0]->r_sprt.top = 540;
		sprite[0]->r_sprt.left = 1590;
	}
	sfRenderWindow_drawText(wd, sprite[0]->text, NULL);
	if (mem != 0 && (min - mem) <= 5) {
		sfRenderWindow_drawSprite(wd, sprite[15]->s_sprt, NULL);
	} else if (mem != 0)
		mem = 0;
}

void day_time(sfRenderWindow *wd, sprite_t **sprite)
{
	text_t text;
	float time = sfTime_asSeconds(sfClock_getElapsedTime(sprite[0]->clock));
	static int hour = 17;
	static int min = 30;

	if (time >= 1) {
		min++;
		sfClock_restart(sprite[0]->clock);
	}
	if (min == 60) {
		hour++;
		min = 0;
	}
	set_time(hour, min, sprite);
	day_event(wd, sprite, hour, min);
}
