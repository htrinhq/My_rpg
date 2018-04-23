/*
** EPITECH PROJECT, 2018
** quests.h
** File description:
** quests.h
*/

#ifndef QUEST_H_
#define QUEST_H_

#include "rpg.h"

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
} npc_t;

quest_t quest_gen(int has_quest);
npc_t npc_gen(void);

#endif

#ifndef QUEST1
#define QUEST1 ("I need a roll of duct tape.\nGet one for me.")
#endif

#ifndef QUEST2
#define QUEST2 ("I need a tube of toothpaste.\nGet one for me.")
#endif

#ifndef QUEST3
#define QUEST3 ("I need a fork.\nGet one for me.")
#endif

#ifndef QUEST4
#define QUEST4 ("I need a file.\nGet one for me.")
#endif

#ifndef QUEST5
#define QUEST5 ("John has been overconfident lately.\nPut him in his place.")
#endif

#ifndef QUEST6
#define QUEST6 ("Henry has been overconfident lately.\nPut him in his place.")
#endif

#ifndef QUEST7
#define QUEST7 ("Niels has been overconfident lately.\nPut him in his place.")
#endif

#ifndef QUEST8
#define QUEST8 ("Florian has been overconfident lately.\nPut him in his place.")
#endif

#ifndef QUEST9
#define QUEST9 ("Antoine has been overconfident lately.\nPut him in his place.")
#endif

#ifndef QUEST10
#define QUEST10 ("Hugo has been overconfident lately.\nPut him in his place.")
#endif

#ifndef MQUEST1
#define MQUEST1 ("Don't miss the morning call !")
#endif

#ifndef MQUEST2
#define MQUEST2 ("\
")
#endif

#ifndef MQUEST3
#define MQUEST3 ("\
")
#endif

#ifndef MQUEST4
#define MQUEST4 ("\
")
#endif

#ifndef MQUEST5
#define MQUEST5 ("\
")
#endif