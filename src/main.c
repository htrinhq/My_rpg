/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"

sfRenderWindow *renderwindow_create(sfRenderWindow *wd)
{
	sfVideoMode v_mode;

	v_mode.width = 1920;
	v_mode.height = 1075;
	v_mode.bitsPerPixel = 32;
	wd = sfRenderWindow_create(v_mode, "The Great Escape",
				sfDefaultStyle, NULL);
	return (wd);
}

text_t **move_cursos_down(text_t **text)
{
	if (text[2]->pos.y == 375 + (3 * 77))
		text[2]->pos.y = 375;
	else
		text[2]->pos.y += 77;
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}

text_t **move_cursos_up(text_t **text)
{
	if (text[2]->pos.y == 375)
		text[2]->pos.y = 375 + (3 * 77);
	else
		text[2]->pos.y -= 77;
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}

text_t **game_event(sfRenderWindow *window, sfEvent event, text_t **text)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyUp))
			text = move_cursos_up(text);
		if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyDown))
			text = move_cursos_down(text);
	}
	return (text);
}


void disp_text(sfRenderWindow *window, text_t **text)
{
	sfRenderWindow_drawText(window, text[0]->text, NULL);
	sfRenderWindow_drawText(window, text[1]->text, NULL);
	sfRenderWindow_drawText(window, text[2]->text, NULL);
}

void game_loop(sfRenderWindow *window, text_t **text)
{
	sfEvent event;
	sprite_t *bg = malloc(sizeof(sprite_t));

	bg = create_sprite(bg, "rsrc/pictures/bg.png");
	while (sfRenderWindow_isOpen(window)) {
		text = game_event(window, event, text);
		sfRenderWindow_drawSprite(window, bg->s_sprt, NULL);
		disp_text(window, text);
		sfRenderWindow_display(window);
	}
}

text_t **initialize_text(text_t **text)
{
	text[0] = malloc(sizeof(text_t));
	text[1] = malloc(sizeof(text_t));
	text[2] = malloc(sizeof(text_t));
	text[0]->font = sfFont_createFromFile("./rsrc/fonts/copyfonts.com_algol-ix.ttf");
	text[0]->text = sfText_create();
	text[0]->pos.x = 550;
	text[0]->pos.y = 125;
	text[1]->text = sfText_create();
	text[1]->pos.x = 820;
	text[1]->pos.y = 372;
	text[2]->text = sfText_create();
	text[2]->pos.x = 770;
	text[2]->pos.y = 375;
	return (text);
}

text_t **set_text_value(text_t **text)
{
	sfText_setString(text[0]->text, "The Great Escape:");
	sfText_setString(text[1]->text, "Continue\nNew Game\nOptions\nQuit");
	sfText_setString(text[2]->text, ">                          <");
	sfText_setFont(text[0]->text, text[0]->font);
	sfText_setFont(text[1]->text, text[0]->font);
	sfText_setFont(text[2]->text, text[0]->font);
	sfText_setCharacterSize(text[0]->text, 90);
	sfText_setCharacterSize(text[1]->text, 60);
	sfText_setCharacterSize(text[2]->text, 60);
	sfText_setColor(text[0]->text, sfColor_fromRGB(255, 255, 255));
	sfText_setColor(text[1]->text, sfColor_fromRGB(255, 255, 255));
	sfText_setColor(text[2]->text, sfColor_fromRGB(255, 255, 255));
	sfText_setPosition(text[0]->text, text[0]->pos);
	sfText_setPosition(text[1]->text, text[1]->pos);
	sfText_setPosition(text[2]->text, text[2]->pos);
	return (text);
}

int main(int argc, char **argv, char**envp)
{
	sfRenderWindow *window = NULL;
	text_t **text = malloc(sizeof(text_t *));

	if (check_env(envp) == 84 || argc != 1 || argv == NULL)
		return (84);
	window = renderwindow_create(window);
	sfRenderWindow_setFramerateLimit(window, 60);
	text = initialize_text(text);
	text = set_text_value(text);
	game_loop(window, text);
	sfRenderWindow_destroy(window);
	return (0);
}
