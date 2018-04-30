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
	if (sfKeyboard_isKeyPressed(sfKeyZ)) {
		map->r_sprt.top -= 10;
		player_animation(player);
	}
	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		map->r_sprt.top += 10;
		player_animation(player);
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ)) {
		map->r_sprt.left -= 10;
		player_animation(player);
	}
	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		map->r_sprt.left += 10;
		player_animation(player);
	}
	sfSprite_setTextureRect(map->s_sprt, map->r_sprt);
	return (map);
}

void game_event2(sfRenderWindow *window, sfEvent event,
		 sprite_t **sprite)
{
	if (event.type == sfEvtKeyPressed)
		sprite[0] = move_player(sprite[0], sprite[1]);
	if (sprite[1]->o_sprt == 1 && (event.mouseButton.x >= 1332 &&
				       event.mouseButton.x <= (1332 + 250)) &&
	    (event.mouseButton.y >= 747 && event.mouseButton.y <= (747 + 95)) &&
	    sfMouse_isButtonPressed(sfMouseLeft))
		sfRenderWindow_destroy(window);
	if (sprite[1]->o_sprt == 1 && (event.mouseButton.x >= 1605 &&
				       event.mouseButton.x <= (1605 + 250)) &&
	    (event.mouseButton.y >= 747 && event.mouseButton.y <= (747 + 95)) &&
	    sfMouse_isButtonPressed(sfMouseLeft)) {
		sprite[1]->o_sprt = 0;
		menu_loop(window);
	}
}

sprite_t **game_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed &&
		    sfKeyboard_isKeyPressed(sfKeyI) && sprite[1]->o_sprt == 0)
			sprite[1]->o_sprt = 1;
		else if (event.type == sfEvtKeyPressed &&
			 sfKeyboard_isKeyPressed(sfKeyI) &&
			 sprite[1]->o_sprt == 1)
				sprite[1]->o_sprt = 0;
		game_event2(window, event, sprite);
	}
	return (sprite);
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
			text[0]->bo = 1;
	}
	return (text);
}

void initialize_sprite2(sprite_t **sprite)
{
	sfVector2f scale = {0.5, 0.5};

	sprite[1]->r_sprt.top = 10;
	sprite[1]->r_sprt.left = 70;
	sprite[1]->r_sprt.width = 136;
	sprite[1]->r_sprt.height = 183;
	sprite[1]->v_sprt.x = 960;
	sprite[1]->v_sprt.y = 540;
	sprite[1]->o_sprt = 0;
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	sfSprite_setPosition(sprite[1]->s_sprt, sprite[1]->v_sprt);
	sfSprite_setScale(sprite[1]->s_sprt, scale);
}

sprite_t **initialize_sprite(sprite_t **sprite)
{
	sfEvent event;

	sprite[0] = malloc(sizeof(sprite_t) * 5);
	sprite[1] = malloc(sizeof(sprite_t) * 5);
	sprite[2] = malloc(sizeof(sprite_t) * 5);
	sprite[2] = create_sprite(sprite[2], "rsrc/pictures/inventory.png");
	sprite[1] = create_sprite(sprite[1], "rsrc/pictures/p1.png");
	sprite[0] = create_sprite(sprite[0], "rsrc/pictures/map.png");
	sprite[0]->r_sprt.top = 1480;
	sprite[0]->r_sprt.left = 1260;
	sprite[0]->r_sprt.width = 1920;
	sprite[0]->r_sprt.height = 1080;
	initialize_sprite2(sprite);
	return (sprite);
}

void disp_text(sfRenderWindow *window, text_t **text)
{
	sfRenderWindow_drawText(window, text[0]->text, NULL);
	sfRenderWindow_drawText(window, text[1]->text, NULL);
	sfRenderWindow_drawText(window, text[2]->text, NULL);
}

void game_loop(sfRenderWindow *window, sprite_t **sprite)
{
	sfEvent event;

	game_event(window, event, sprite);
	sfRenderWindow_drawSprite(window, sprite[0]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[1]->s_sprt, NULL);
	if (sprite[1]->o_sprt == 1)
		sfRenderWindow_drawSprite(window, sprite[2]->s_sprt, NULL);
	sfRenderWindow_display(window);
}

void menu_loop(sfRenderWindow *window)
{
	text_t **text = malloc(sizeof(text_t *) * 5);
	sprite_t *bg = malloc(sizeof(sprite_t));
	sfEvent event;
	sprite_t **sprite = malloc(sizeof(sprite_t *) * 4);

	sprite = initialize_sprite(sprite);
	sprite = game_event(window, event, sprite);
	text = initialize_text(text);
	text = set_text_value(text);
	bg = create_sprite(bg, "rsrc/pictures/bg.png");
	while (sfRenderWindow_isOpen(window)) {
		if (text[0]->bo == 0) {
			text = menu_event(window, event, text);
			sfRenderWindow_drawSprite(window, bg->s_sprt, NULL);
			disp_text(window, text);
			sfRenderWindow_display(window);
		} else {
			game_loop(window, sprite);
		}
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
	sfMusic *music = sfMusic_createFromFile("rsrc/sounds/main.ogg");
	idobj_t **obj = malloc(sizeof(id_t *) * 16);
	chest_t **chests = NULL;

	chests = create_chests(chests);
	if (check_env(envp) == 84 || argc != 1 || argv == NULL)
		return (84);
	sfMusic_play(music);
	if (check_env(envp) == 84 || argc != 1 || argv == NULL)
		return (84);
	obj = fill_obj_id(obj);
	window = renderwindow_create(window);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfMusic_destroy(music);
	menu_loop(window);
	return (0);
}
