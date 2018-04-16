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

void game_event(sfRenderWindow *window, sfEvent event)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
}

void disp_text(sfRenderWindow *window)
{
	sfText *start = sfText_create();
	sfText *corps = sfText_create();
	sfFont *font = sfFont_createFromFile("./rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfVector2f origin = {550, 100};
	sfVector2f under = {750, 350};
	sfText_setString(start, "The Great Escape:");
	sfText_setString(corps, "Continue\nNew Game\nOptions\nQuit");
	sfText_setFont(corps, font);
	sfText_setFont(start, font);
	sfText_setCharacterSize(start, 100);
	sfText_setCharacterSize(corps, 70);
	sfText_setColor(start, sfColor_fromRGB(255, 255, 255));
	sfText_setColor(corps, sfColor_fromRGB(255, 255, 255));
	sfText_move(start, origin);
	sfText_move(corps, under);
	sfRenderWindow_drawText(window, start, NULL);
	sfRenderWindow_drawText(window, corps, NULL);
	sfText_destroy(start);
	sfText_destroy(corps);
	sfFont_destroy(font);
}

void game_loop(sfRenderWindow *window)
{
	sfEvent event;
	sprite_t *arrow = malloc(sizeof(sprite_t) * 1);

	arrow = create_sprite(arrow, "rsrc/pictures/arrow_sheet.png");
	while (sfRenderWindow_isOpen(window)) {
		game_event(window, event);
		sfRenderWindow_drawSprite(window, arrow->s_sprt, NULL);
		disp_text(window);
		sfRenderWindow_display(window);
	}
}

int main(int argc, char **argv, char**envp)
{
	sfRenderWindow *window = NULL;

	if (check_env(envp) == 84 || argc != 1 || argv == NULL)
		return (84);
	window = renderwindow_create(window);
	sfRenderWindow_setFramerateLimit(window, 60);
	game_loop(window);
	sfRenderWindow_destroy(window);
	return (0);
}
