/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** structures for rpg
*/

#ifndef STRUCT_H
#define STRUCT_H

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
	int *inventory;
	int ch;
	sprite_t **s_obj;
	sfMusic *chest;
	sfMusic *punch;
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
	char **map;
} guard_t;

#endif
