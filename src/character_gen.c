/*
** EPITECH PROJECT, 2018
** character_gen.c
** File description:
** character_gen.c
*/

#include "rpg.h"

int rand_gen(int min, int max)
{
	int i = 0;

	max = max + 1;
	i = rand() % (max - min);
	return (i + min);
}

quest_t quest_gen(int has_quest)
{
	quest_t quest;

	if (has_quest == 1) {
		quest.bo = 1;
		quest.main_q = 0;
		quest.q_id = rand_gen(1, 10);
	} else {
		quest.bo = 0;
		quest.main_q = 0;
		quest.q_id = -1;
	}
	return (quest);
}

npcst_t stat_gen(void)
{
	npcst_t stat;

	stat.strength = rand_gen(20, 60);
	stat.max_lp = 100;
	stat.lp = 100;
	stat.level = 1;
	return (stat);
}

npc_t *npc_gen(void)
{
	npc_t *npc = malloc(sizeof(npc_t));
	int sprite_id = 0;
	int i = 0;
	char *s = malloc(sizeof(char) * 23);
	static int token = 48;

	sprite_id = rand_gen(2, 28);
	s = my_strcat("rsrc/pictures/p", 3, my_int_to_str(sprite_id), ".png");
	npc->spr = find_sprite(s);
	npc->quest = quest_gen(rand_gen(1, 3));
	npc->stat = stat_gen();
	npc->inventory = malloc(sizeof(int) * 18);
	npc->token = token;
	npc->spr->r_sprt = create_recth(0, 0, 320, 320);
	while (i < 18) {
		npc->inventory[i] = -1;
		i = i + 1;
	}
	token = token + 1;
	return (npc);
}

npc_t **get_all_npcs(int npc_nb)
{
	int i = 0;
	npc_t **npcs = malloc(sizeof(npc_t*) * (npc_nb + 1));

	while (i < npc_nb) {
		npcs[i] = malloc(sizeof(npc_t));
		npcs[i] = npc_gen();
		i = i + 1;
	}
	get_npc(1, npcs);
	return (npcs);
}