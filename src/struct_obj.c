/*
** EPITECH PROJECT, 2017
** struct_obj.c
** File description:
** function to fill the ID of the objects
*/

#include "rpg.h"

idobj_t **fill_obj_id(idobj_t **obj)
{
	obj[0] = malloc(sizeof(idobj_t));
	obj[0]->path = my_strdup("rsrc/pictures/bear.png");
	obj[0]->id = 0;
	obj[1] = malloc(sizeof(idobj_t));
	obj[1]->path = my_strdup("rsrc/pictures/book.png");
	obj[1]->id = 1;
	obj[2] = malloc(sizeof(idobj_t));
	obj[2]->path = my_strdup("rsrc/pictures/chauss.png");
	obj[2]->id = 2;
	obj[3] = malloc(sizeof(idobj_t));
	obj[3]->path = my_strdup("rsrc/pictures/fork.png");
	obj[3]->id = 3;
	obj[4] = malloc(sizeof(idobj_t));
	obj[4]->path = my_strdup("rsrc/pictures/glass.png");
	obj[4]->id = 4;
	obj[5] = malloc(sizeof(idobj_t));
	obj[5]->path = my_strdup("rsrc/pictures/key.png");
	obj[5]->id = 5;
	obj[6] = malloc(sizeof(idobj_t));
	obj[6]->path = my_strdup("rsrc/pictures/knife.png");
	obj[6]->id = 6;
	obj[7] = malloc(sizeof(idobj_t));
	obj[7]->path = my_strdup("rsrc/pictures/lime.png");
	obj[7]->id = 7;
	obj[8] = malloc(sizeof(idobj_t));
	obj[8]->path = my_strdup("rsrc/pictures/phone.png");
	obj[8]->id = 8;
	obj[9] = malloc(sizeof(idobj_t));
	obj[9]->path = my_strdup("rsrc/pictures/savon.png");
	obj[9]->id = 9;
	obj[10] = malloc(sizeof(idobj_t));
	obj[10]->path = my_strdup("rsrc/pictures/scotch.png");
	obj[10]->id = 10;
	obj[11] = malloc(sizeof(idobj_t));
	obj[11]->path = my_strdup("rsrc/pictures/screwdriver.png");
	obj[11]->id = 11;
	obj[12] = malloc(sizeof(idobj_t));
	obj[12]->path = my_strdup("rsrc/pictures/shaver.png");
	obj[12]->id = 12;
	obj[13] = malloc(sizeof(idobj_t));
	obj[13]->path = my_strdup("rsrc/pictures/toothpaste.png");
	obj[13]->id = 13;
	obj[14] = malloc(sizeof(idobj_t));
	obj[14]->path = my_strdup("rsrc/pictures/wisky.png");
	obj[14]->id = 14;
	return (obj);
}
