/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <sys/types.h>
#include <dirent.h>
#include "my_printf.h"
#include "graph.h"

typedef struct id {
	char *path;
	int id;
} idobj_t;

typedef struct stat_npc {
	int level;
	int max_lp;
	int lp;
	int strength;
} npcst_t;

#include "quests.h"

void game_loop(sfRenderWindow *window);
int check_env(char **envp);
char **get_paths(void);
int my_tablen(char **tab);
void display_tab(char **tab);
int my_dirlen(DIR *directory);
int check_name(char *name);
sprite_t **get_sprite(int bo, sprite_t **sprite);
sprite_t **create_sprite_tab(void);
npcst_t stat_gen(void);
sprite_t *find_sprite(char *name);
char *my_revstr(char *str);
char *my_int_to_str(int nb);
idobj_t **fill_obj_id(idobj_t **obj);
int my_strcmp(char const *s1, char const *s2);

#endif
