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

void day_time(sfRenderWindow *wd, sprite_t **sprite)
{
	text_t text;
	float time = sfTime_asSeconds(sfClock_getElapsedTime(sprite[0]->clock));
	static int hour = 9;
	static int min = 55;

	if (time >= 1) {
		min++;
		sfClock_restart(sprite[0]->clock);
	}
	if (min == 60) {
		hour++;
		min = 0;
	}
	set_time(hour, min, sprite);
	sfRenderWindow_drawText(wd, sprite[0]->text, NULL);
}
