/*
** EPITECH PROJECT, 2018
** quests.h
** File description:
** quests.h
*/

#ifndef QUEST_H_
#define QUEST_H_

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
} npc_t;

quest_t quest_gen(int has_quest);
npc_t *npc_gen(void);
npc_t **get_npc(int bo, npc_t **npc);

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
#define MQUEST2 ("You need to eat!")
#endif

#ifndef MQUEST3
#define MQUEST3 ("Talk to Niels, I think he needs something...")
#endif

#ifndef MQUEST4
#define MQUEST4 ("Don't miss the daytasks!")
#endif

#ifndef MQUEST5
#define MQUEST5 ("Find a screwdriver")
#endif

#ifndef MQUEST6
#define MQUEST6 ("Find a way to the Internet Room")
#endif

#ifndef MQUEST7
#define MQUEST7 ("F**k, there's no phone here! I need to go to the Director's Office to get one. I will surely need to create a diversion to get there..")
#endif
