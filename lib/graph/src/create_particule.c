/*
** EPITECH PROJECT, 2018
** lib graph
** File description:
** lib graph
*/

#include "graph.h"

sfVertex *create_vertex(sfVector2f pos, int s_x, int s_y)
{
	sfVertex *vertex = malloc(40 * sizeof(sfVertex));

	if (vertex == NULL)
		return (NULL);
	for (int i = 0; i < 10 ; i++) {
		vertex[i * 4 + 0].position = (sfVector2f){pos.x,
			pos.y};
		vertex[i * 4 + 1].position = (sfVector2f)
		{pos.x + 10, pos.y};
		vertex[i * 4 + 2].position = (sfVector2f)
		{pos.x + 10, pos.y + 10};
		vertex[i * 4 + 3].position = (sfVector2f)
		{pos.x, pos.y + 10};
		s_x = rand() % 20;
		s_y = rand() % 20;
		for (int x = 0; x < 4; x++) {
			vertex[i * 4 + x].position.x +=  s_x;
			vertex[i * 4 + x].position.y +=  s_y;
		}
	}
	return (vertex);
}

void particules(sfRenderWindow *window, int x, int y, int color)
{
	sfVector2f pos = {x, y};
	sfVertex *vertex = create_vertex(pos, 0, 0);
	sfShader *shader = sfShader_createFromFile(NULL,
	"lib/graph/shaders/blood.frag");
	sfRenderStates state = {sfBlendAlpha, sfTransform_Identity, NULL,
		shader};

	if (vertex == NULL)
		return;
	if (color == 0)
		sfShader_setFloatParameter(shader, "clr_r",
		(float)(rand() % 200) / 100);
	else {
		sfShader_setFloatParameter(shader, "clr_r", 0.7);
		sfShader_setFloatParameter(shader, "clr_g", 0.6);
		sfShader_setFloatParameter(shader, "clr_b", 0.4);
	}
	sfRenderWindow_drawPrimitives(window, vertex, 10, sfQuads, &state);
	sfShader_destroy(shader);
	free(vertex);
}
