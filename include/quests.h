/*
** EPITECH PROJECT, 2018
** quests.h
** File description:
** quests.h
*/

#ifndef QUEST_H_
#define QUEST_H_

#include "struct.h"

typedef struct quest {
	int bo;
	int main_q;
	int q_id;
} quest_t;

typedef struct npc {
	sprite_t *spr;
	npcst_t stat;
	quest_t quest;
	int *inventory;
	char *name;
	sfVector2f pos;
	char token;
	char **map;
} npc_t;

quest_t quest_gen(int has_quest);
npc_t *npc_gen(void);
npc_t **get_npc(int bo, npc_t **npc);

#endif
