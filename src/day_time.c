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

int delta_time(int t1, int t2)
{
	if (t2 - t1 < 0)
		t2 += 60;
	if (t2 - t1 > 60)
		t2 -= 60;
	return (t2 - t1);
}

int call(sprite_t **sprite, int mem, int min, int hour)
{
	if (hour >= 7 && hour < 8 && min % 2 == 0)
		sfText_setString(sprite[0]->text, "!!! GO TO CALL !!!");
	if (hour >= 8 && hour < 9 && sprite[15]->o_sprt == 0 && min < 20 &&
	(sprite[0]->r_sprt.top < 570 || sprite[0]->r_sprt.top > 1260 ||
	sprite[0]->r_sprt.left < 520 || sprite[0]->r_sprt.left > 1650) &&
	sprite[0]->r_sprt.left != 540 && sprite[0]->r_sprt.left != 1590) {
		mem = min;
		sprite[15]->o_sprt = 1;
		sprite[0]->r_sprt.top = 540;
		sprite[0]->r_sprt.left = 1590;
	}
	return (mem);
}

int shower(sprite_t **sprite, int mem, int min, int hour)
{
	if (hour >= 15 && hour < 16 && min % 2 == 0)
		sfText_setString(sprite[0]->text, "!!! GO TO SHOWER !!!");
	if (hour >= 16 && hour < 17 && sprite[15]->o_sprt == 0 && min < 20 &&
	(sprite[0]->r_sprt.top < 270 || sprite[0]->r_sprt.top > 1260 ||
	sprite[0]->r_sprt.left < 1220 || sprite[0]->r_sprt.left > 1650) &&
	sprite[0]->r_sprt.left != 540 && sprite[0]->r_sprt.left != 1590) {
		mem = min;
		sprite[15]->o_sprt = 1;
		sprite[0]->r_sprt.top = 540;
		sprite[0]->r_sprt.left = 1590;
	}
	return (mem);
}

int eat(sprite_t **sprite, int mem, int min, int hour)
{
	if (hour >= 12 && hour < 13 && min % 2 == 0)
		sfText_setString(sprite[0]->text, "!!! GO EAT !!!");
	if (hour >= 13 && hour < 14 && sprite[15]->o_sprt == 0 && min < 20 &&
	(sprite[0]->r_sprt.top < 270 || sprite[0]->r_sprt.top > 710 ||
	sprite[0]->r_sprt.left < -60 || sprite[0]->r_sprt.left > 440) &&
	sprite[0]->r_sprt.left != 540 && sprite[0]->r_sprt.left != 1590) {
		mem = min;
		sprite[15]->o_sprt = 1;
		sprite[0]->r_sprt.top = 540;
		sprite[0]->r_sprt.left = 1590;
	}
	return (mem);
}


int night(sprite_t **sprite, int mem, int min, int hour)
{
	if (hour >= 18 && hour < 19 && min % 2 == 0)
		sfText_setString(sprite[0]->text, "!!! GO TO SLEEP !!!");
	if (hour >= 19 && hour < 20 && sprite[15]->o_sprt == 0 &&
	(sprite[0]->r_sprt.top < 1370 || sprite[0]->r_sprt.top > 1710 ||
	sprite[0]->r_sprt.left < 1130 || sprite[0]->r_sprt.left > 1440) &&
	sprite[0]->r_sprt.left != 540 && sprite[0]->r_sprt.left != 1590) {
		mem = min;
		sprite[15]->o_sprt = 1;
		sprite[0]->r_sprt.top = 540;
		sprite[0]->r_sprt.left = 1590;
	}
	return (mem);
}

void day_event(sfRenderWindow *wd, sprite_t **sprite, int hour, int min)
{
	static int mem = 0;

	mem = night(sprite, mem, min, hour);
	mem = eat(sprite, mem, min, hour);
	mem = call(sprite, mem, min, hour);
	mem = shower(sprite, mem, min, hour);
	sfRenderWindow_drawText(wd, sprite[0]->text, NULL);
	if (sprite[15]->o_sprt == 1)
		sfRenderWindow_drawSprite(wd, sprite[15]->s_sprt, NULL);
	if (sprite[15]->o_sprt == 1 && delta_time(mem, min) >= 5)
		sprite[15]->o_sprt = 0;
}

void day_time(sfRenderWindow *wd, sprite_t **sprite)
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
	if (hour == 20)
		hour = 7;
	set_time(hour, min, sprite);
	day_event(wd, sprite, hour, min);
}
