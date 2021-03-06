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
#include "get_next_line.h"
#include "my_printf.h"
#include "graph.h"
#include "quests.h"
#include "struct.h"

void day_time(sfRenderWindow *wd, sprite_t **sprite,
plstat_t *stat);
int delta_time(int t1, int t2);
void game_loop(sfRenderWindow *window, sprite_t **sprite,
icm_t *icm,
plstat_t *stat);
void day_event(sfRenderWindow *wd, sprite_t **sprite, int hour, int min);
int detect_chest(int x, int y, sprite_t **sprite);
void display_stat(sprite_t **sprite, sfRenderWindow *window,
plstat_t *stat);
int count_weapons(icm_t *icm);
void display_inside(chest_t *chests, icm_t *icm,
sfRenderWindow *window);
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
chest_t **create_chests(chest_t **chests);
idobj_t **fill_obj_id(idobj_t **obj);
void display_inventory2(sfRenderWindow *window, icm_t *icm);
void display_inventory3(sfRenderWindow *window, icm_t *icm);
void display_inventory7(sfRenderWindow *window, icm_t *icm);
void display_inventory8(sfRenderWindow *window, icm_t *icm);
void display_inventory4(sfRenderWindow *window, icm_t *icm);
void display_inventory5(sfRenderWindow *window, icm_t *icm);
void display_inventory6(sfRenderWindow *window, icm_t *icm);
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
sfVector2f get_pos_routine3(char **map, char token);
sprite_t **fill_obj_sprite(sprite_t **obj);
void display_chest(int x, int y, icm_t *icm, sfRenderWindow *window);
void display_guards(sfRenderWindow *window, sfIntRect rect, float a);
void display_guards2(sfRenderWindow *window, sfIntRect rect, guard_t *guard);
int *create_inventory(int *inventory);
void display_inventory(sfRenderWindow *window, icm_t *icm);
int add_inventory(int id, icm_t *icm);
int add_chest(int id, icm_t *icm, int nb);
sfVector2f get_real_pos(char **map, char token, sfIntRect rect);
char **read_routes(char *path);
void read_npc_routes(void);
guard_t **get_all_guards(int guards_nb);
npc_t **get_all_npcs(int npc_nb);
void init_var(void);
sfIntRect npc_animation(sfIntRect rect);
void display_npc(sfRenderWindow *window, sfIntRect rect, sprite_t *sprite);
text_t **move_cursos_down(text_t **text);
text_t **move_cursos_up(text_t **text);
sprite_t **player_animation(sprite_t **sprite, int x, int y);
sprite_t **move_player(sprite_t **sprite, icm_t *icm, int pst);
sprite_t **game_event(sfRenderWindow *window, sfEvent event,
sprite_t **sprite, icm_t *icm);
void change_ch_inv(icm_t *icm, int id);
void change_inv_ch(icm_t *icm, int id);
void change_chest(sfEvent event, icm_t *icm);
text_t **menu_event(sfRenderWindow *window, sfEvent event, text_t **text,
sprite_t **sprite);
void dlc_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite);
void pause_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite);
void disp_text(sfRenderWindow *window, text_t **text);
void create_icm_stat_text(plstat_t *stat, sprite_t **sprite,
icm_t *icm, text_t **text);
text_t **initialize_text(text_t **text);
text_t **set_text_value(text_t **text);
void initialize_stat(plstat_t *stat);
void menu_loop(sfRenderWindow *window, icm_t *icm);
void dlc_loop(sfRenderWindow *window, sprite_t **sprite);
void pause_loop(sfRenderWindow *window, sprite_t **sprite);
void fight(plstat_t *stat, sprite_t **sprite, sfRenderWindow *window,
icm_t *icm);
char **get_map_txt(void);
sprite_t **initialize_sprite(sprite_t **sprite, plstat_t *stat);
void set_rect(sprite_t **sprite, plstat_t *stat);
void set_rect_2(sprite_t **sprite, plstat_t *stat, int level);
void set_rect_3(sprite_t **sprite);
void set_o_sprt(sprite_t **sprite);
void set_texture_rect(sprite_t **sprite);
void set_position(sprite_t **sprite);
void set_scale(sprite_t **sprite);
int count_intel(icm_t *icm);

#endif
