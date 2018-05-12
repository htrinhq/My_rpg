/*
** EPITECH PROJECT, 2018
** sprites.c
** File description:
** sprites.c
*/

#include "rpg.h"

sprite_t **create_sprite_tab(void)
{
	char **paths = get_paths();
	sprite_t **sprite = malloc(sizeof(sprite_t*) * (my_tablen(paths) + 1));
	int i = 0;

	while (paths[i] != NULL) {
		sprite[i] = malloc(sizeof(sprite_t));
		sprite[i] = create_sprite(sprite[i],
		my_strcat("rsrc/pictures/", 2, paths[i]));
		sprite[i]->name = my_strcat("rsrc/pictures/", 2, paths[i]);
		i = i + 1;
	}
	sprite[i] = NULL;
	get_sprite(1, sprite);
	return (sprite);
}

char **get_paths(void)
{
	DIR *directory = opendir("rsrc/pictures");
	struct dirent *buf;
	char **paths = malloc(sizeof(char*) * (my_dirlen(directory) + 1));
	int i = 0;

	directory = opendir("rsrc/pictures");
	if (directory == NULL)
		return (NULL);
	buf = readdir(directory);
	while (buf != NULL) {
		if (check_name(buf->d_name)) {
			paths[i] = my_strdup(buf->d_name);
			i = i + 1;
		}
		buf = readdir(directory);
	}
	closedir(directory);
	paths[i] = NULL;
	return (paths);
}

int my_dirlen(DIR *directory)
{
	struct dirent *buf;
	int i = 0;

	if (directory == NULL)
		return (0);
	buf = readdir(directory);
	while (buf != NULL) {
		if (check_name(buf->d_name))
			i = i + 1;
		buf = readdir(directory);
	}
	closedir(directory);
	return (i);
}

int check_name(char *name)
{
	int i = 0;

	while (name[i] != '.')
		i = i + 1;
	if (name[i + 1] == 'p' && name[i + 2] == 'n' && name[i + 3] == 'g' &&
		name[i + 4] == '\0')
		return (1);
	else
		return (0);
}

int my_tablen(char **tab)
{
	int i = 0;

	while (tab[i] != NULL)
		i = i + 1;
	return (i);
}
