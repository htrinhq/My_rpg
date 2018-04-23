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

void player_animation(sprite_t *player)
{
	player->r_sprt.top += 320;
	if (player->r_sprt.top == 970)
		player->r_sprt.top = 10;
	sfSprite_setTextureRect(player->s_sprt, player->r_sprt);
}

sprite_t *move_player(sprite_t *map, sprite_t *player)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		map->r_sprt.top -= 10;
		player_animation(player);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		map->r_sprt.top += 10;
		player_animation(player);
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		map->r_sprt.left -= 10;
		player_animation(player);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		map->r_sprt.left += 10;
		player_animation(player);
	}
	sfSprite_setTextureRect(map->s_sprt, map->r_sprt);
	return (map);
}

sprite_t *game_event(sfRenderWindow *window, sfEvent event, sprite_t *map, sprite_t *player)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape) && player->o_sprt == 0)
			player->o_sprt = 1;
		else if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape) && player->o_sprt == 1)
			player->o_sprt = 0;
		if (event.type == sfEvtKeyPressed) {
			map = move_player(map, player);
		}
	}
	return (map);
}

text_t **menu_event(sfRenderWindow *window, sfEvent event, text_t **text)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyUp) && text[0]->bo == 0)
			text = move_cursos_up(text);
		if (event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyDown) && text[0]->bo == 0)
			text = move_cursos_down(text);
		if (event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyReturn) && text[0]->bo == 0 &&
		text[2]->pos.y == 375 + (3 * 77))
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyReturn) && text[0]->bo == 0 &&
		text[2]->pos.y == 375 + 77)
			game_loop(window);
	}
	return (text);
}

void disp_text(sfRenderWindow *window, text_t **text)
{
	sfRenderWindow_drawText(window, text[0]->text, NULL);
	sfRenderWindow_drawText(window, text[1]->text, NULL);
	sfRenderWindow_drawText(window, text[2]->text, NULL);
}

void game_loop(sfRenderWindow *window)
{
	sprite_t *inventory = malloc(sizeof(sprite_t));
	sprite_t *player = malloc(sizeof(sprite_t));
	sprite_t *map = malloc(sizeof(sprite_t));
	sfVector2f scale = {0.5, 0.5};
	sfEvent event;

	inventory = create_sprite(inventory, "rsrc/pictures/inventory.png");
	player = create_sprite(player, "rsrc/pictures/p1.png");
	map = create_sprite(map, "rsrc/pictures/map.png");
	map->r_sprt.top = 1480;
	map->r_sprt.left = 1260;
	map->r_sprt.width = 1920;
	map->r_sprt.height = 1080;
	player->r_sprt.top = 10;
	player->r_sprt.left = 70;
	player->r_sprt.width = 136;
	player->r_sprt.height = 183;
	player->v_sprt.x = 960;
	player->v_sprt.y = 540;
	sfSprite_setTextureRect(map->s_sprt, map->r_sprt);
	sfSprite_setTextureRect(player->s_sprt, player->r_sprt);
	sfSprite_setPosition(player->s_sprt, player->v_sprt);
	sfSprite_setScale(player->s_sprt, scale);
	while (sfRenderWindow_isOpen(window)) {
		map = game_event(window, event, map, player);
		sfRenderWindow_drawSprite(window, map->s_sprt, NULL);
		sfRenderWindow_drawSprite(window, player->s_sprt, NULL);
		if (player->o_sprt == 1)
			sfRenderWindow_drawSprite(window, inventory->s_sprt, NULL);
		sfRenderWindow_display(window);
	}
}

void menu_loop(sfRenderWindow *window, text_t **text)
{
	sfEvent event;
	sprite_t *bg = malloc(sizeof(sprite_t));

	bg = create_sprite(bg, "rsrc/pictures/bg.png");
	while (sfRenderWindow_isOpen(window)) {
		text = menu_event(window, event, text);
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
	text[0]->bo = 0;
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
	menu_loop(window, text);
	sfRenderWindow_destroy(window);
	return (0);
}
