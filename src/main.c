/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"

float game_clock(void)
{
	sfClock *clock = sfClock_create();
	float a = sfTime_asMicroseconds(sfClock_getElapsedTime(clock));

	return (a);
}

sfRenderWindow *renderwindow_create(sfRenderWindow *wd)
{
	sfVideoMode v_mode;

	v_mode.width = 1920;
	v_mode.height = 1075;
	v_mode.bitsPerPixel = 32;
	wd = sfRenderWindow_create(v_mode, "The Great Escape",
	sfDefaultStyle, NULL);
	return (wd);
}

char **get_map_txt(void)
{
	char **map_txt = malloc(sizeof(char *) * 310);
	int fd = open("rsrc/map.txt", O_RDONLY);

	if (map_txt == NULL || fd == -1)
		return (NULL);
	for (int i = 0; i < 304; i = i + 2) {
		map_txt[i] = get_next_line(fd);
		map_txt[i + 1] = my_strdup(map_txt[i]);;
	}
	map_txt[305] = NULL;
	return (map_txt);
}

void get_icm(icm_t *icm)
{
	icm->obj = malloc(sizeof(idobj_t *) * 16);
	icm->s_obj = malloc(sizeof(sprite_t *) * 15);
	icm->inventory = malloc(sizeof(int) * 17);
	icm->inventory = create_inventory(icm->inventory);
	icm->chests = create_chests(icm->chests);
	icm->s_obj = fill_obj_sprite(icm->s_obj);
}

int main(int argc, char **argv, char**envp)
{
	sfRenderWindow *window = NULL;
	sfMusic *music;
	icm_t *icm = malloc(sizeof(icm_t));

	srand((unsigned long) &icm);
	get_icm(icm);
	if (check_env(envp) == 84 || argc != 1 || argv == NULL)
		return (84);
	init_var();
	music = sfMusic_createFromFile("rsrc/sounds/main.ogg");
	sfMusic_play(music);
	icm->obj = fill_obj_id(icm->obj);
	window = renderwindow_create(window);
	sfRenderWindow_setFramerateLimit(window, 60);
	menu_loop(window, icm);
	sfMusic_destroy(music);
	return (0);
}
