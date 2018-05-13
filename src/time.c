/*
** EPITECH PROJECT, 2017
** time.c
** File description:
** desc
*/

#include "rpg.h"

void set_time_2(int hour, int min, sprite_t **sprite)
{
	if (min == 0) {
		sfText_setString(sprite[0]->text,
		my_strcat(my_int_to_str(hour), 4, " : ", "0", "0"));
		return;
	}
	if (min < 10) {
		sfText_setString(sprite[0]->text,
		my_strcat(my_int_to_str(hour), 4, " : ", "0",
		my_int_to_str(min)));
		return;
	}
	sfText_setString(sprite[0]->text,
	my_strcat(my_int_to_str(hour), 3, " : ", my_int_to_str(min)));
}

void set_time(int hour, int min, sprite_t **sprite)
{
	if (hour == 0 && min == 0) {
		sfText_setString(sprite[0]->text,
		my_strcat("0", 3, " : ", "00"));
		return;
	}
	if (hour == 0 && min < 10) {
		sfText_setString(sprite[0]->text,
		my_strcat("0", 4, " : ", "0", my_int_to_str(min)));
		return;
	}
	if (hour == 0) {
		sfText_setString(sprite[0]->text,
		my_strcat("0", 3, " : ", my_int_to_str(min)));
		return;
	}
	set_time_2(hour, min, sprite);
}

int delta_time(int t1, int t2)
{
	if (t2 - t1 < 0)
		t2 += 60;
	if (t2 - t1 > 60)
		t2 -= 60;
	return (t2 - t1);
}

void update_stat(plstat_t *stat)
{
	stat->xp += 100;
	stat->force += 1;
	stat->inteligence += 1;
	stat->speed += 1;
}

void day_time(sfRenderWindow *wd, sprite_t **sprite, plstat_t *stat)
{
	float time = sfTime_asSeconds(sfClock_getElapsedTime(sprite[0]->clock));
	static int hour = 7;
	static int min = 42;

	if (time >= 1) {
		min++;
		sfClock_restart(sprite[0]->clock);
	}
	if (min == 60) {
		hour++;
		min = 0;
	}
	if (hour == 20) {
		hour = 7;
		update_stat(stat);
	}
	set_time(hour, min, sprite);
	day_event(wd, sprite, hour, min);
}
