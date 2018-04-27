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

typedef struct guards {
	sprite_t *sprite;
	npcst_t stat;
} guard_t;

#include "quests.h"

void game_loop();
int check_env(char **envp);
char **get_paths(void);
int my_tablen(char **tab);
void display_tab(char **tab);
int my_dirlen(DIR *directory);
int check_name(char *name);
int rand_gen(int min, int max);
sprite_t **get_sprite(int bo, sprite_t **sprite);
sprite_t **create_sprite_tab(void);
npcst_t stat_gen(void);
sprite_t *find_sprite(char *name);
char *my_revstr(char *str);
char *my_int_to_str(int nb);
idobj_t **fill_obj_id(idobj_t **obj);
void menu_loop();
text_t **set_text_value();
text_t **initialize_text();
int my_strcmp(char const *s1, char const *s2);
int *shift_inventory(int *inventory);
int *spawn_objects(void);
int spawn_obj_id(void);
int *player_take_obj(int *inventory, int obj_id);
void display_obj(int *inventory, idobj_t **obj);
guard_t **get_guards(int bo, guard_t **guards);

#endif
