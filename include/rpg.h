/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include <sys/types.h>
#include <dirent.h>
#include "get_next_line.h"
#include "my_printf.h"
#include "graph.h"

#ifndef RPG_H_
#define RPG_H_

typedef struct id {
	char *path;
	int id;
} idobj_t;

typedef struct chest {
	int *inside;
	int name;
} chest_t;

typedef struct icm {
	char **map_txt;
	idobj_t **obj;
	chest_t **chests;
} icm_t;

typedef struct stat_npc {
	int level;
	int max_lp;
	int lp;
	int strength;
} npcst_t;

typedef struct stat_pl {
	int xp;
	int force;
	int inteligence;
	int life;
	int speed;
	sprite_t **sprite;
} plstat_t;

typedef struct guards {
	sprite_t *sprite;
	npcst_t stat;
	sfVector2f pos;
	char token;
} guard_t;

#include "quests.h"

char *my_getnbr();
int detect_chest();
void game_loop();
void display_stat();
int check_env(char **envp);
void initialize_stat();
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
chest_t **create_chests(chest_t **chests);
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
float game_clock(void);
sfVector2f find_character(char **map, char token);
int find_token(char *str, sfVector2f *pos, char token);
void follow(char follower, sfVector2f pos, char **map);
void follow2(char follower, char **map, sfVector2f pos, sfVector2f pos_f);
void basic_move(char follower, char **map, sfVector2f pos_f);
sfVector2f get_pos_routine(char token, char **map);
sfVector2f get_pos_routine2(char **map, char token);

#endif
