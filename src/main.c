/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"

float game_clock(void)
{
	sfClock *clock = sfClock_create();
	float a = sfTime_asMicroseconds(sfClock_getElapsedTime(clock));

	return (a);
}

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

sprite_t **player_animation(sprite_t **sprite, int x, int y)
{
	if (game_clock() > 0.46)
		sprite[1]->r_sprt.top += 320;
	if (sprite[1]->r_sprt.top == 970)
		sprite[1]->r_sprt.top = 10;
	sprite[4]->v_sprt.x = y / 2 - 6;
	sprite[4]->v_sprt.y = x / 2 - 15;
	sfSprite_setPosition(sprite[4]->s_sprt, sprite[4]->v_sprt);
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	return (sprite);
}

sprite_t **move_player(sprite_t **sprite, char **map_txt)
{
	static int y = 225;
	static int x = 213;

	if (sfKeyboard_isKeyPressed(sfKeyZ) && x > 0 && map_txt[x - 1][y] == ' ') {
		sprite[0]->r_sprt.top -= 10;
		x--;
	}
	if (sfKeyboard_isKeyPressed(sfKeyS) && x < 3050 && map_txt[x + 1][y] == ' ') {
		sprite[0]->r_sprt.top += 10;
		x++;
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ) && y > 0 && map_txt[x][y - 1] == ' ') {
		sprite[0]->r_sprt.left -= 10;
		y--;
	}
	if (sfKeyboard_isKeyPressed(sfKeyD) && y < 4600 && map_txt[x][y + 1] == ' ') {
		sprite[0]->r_sprt.left += 10;
		y++;
	}
	return (player_animation(sprite, x, y));
}

void game_event2(sfRenderWindow *window, sfEvent event,
		 sprite_t **sprite, char **map_txt)
{
	if (sprite[5]->o_sprt == 3 && (event.mouseButton.x >= 1332 &&
				       event.mouseButton.x <= (1332 + 250)) &&
	    (event.mouseButton.y >= 747 && event.mouseButton.y <= (747 + 95)) &&
	    sfMouse_isButtonPressed(sfMouseLeft))
		sfRenderWindow_destroy(window);
	if (sprite[5]->o_sprt == 3 && (event.mouseButton.x >= 1605 &&
				       event.mouseButton.x <= (1605 + 250)) &&
	    (event.mouseButton.y >= 747 && event.mouseButton.y <= (747 + 95)) &&
	    sfMouse_isButtonPressed(sfMouseLeft)) {
		sprite[1]->o_sprt = 0;
		sprite[5]->o_sprt = 0;
	}
	if (event.type != sfEvtKeyPressed)
		return;
	if (sfKeyboard_isKeyPressed(sfKeyP))
		sprite[5]->o_sprt = 3;
	if (sfKeyboard_isKeyPressed(sfKeyI))
		sprite[2]->o_sprt = (sprite[2]->o_sprt == 0) ? 1 : 0;
	sprite = move_player(sprite, map_txt);
}

sprite_t **game_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite, char **map_txt)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else
			game_event2(window, event, sprite, map_txt);
	}
	return (sprite);
}

text_t **menu_event(sfRenderWindow *window, sfEvent event, text_t **text, sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyUp) && sprite[5]->o_sprt == 0)
			text = move_cursos_up(text);
		if (sfKeyboard_isKeyPressed(sfKeyDown) && sprite[5]->o_sprt == 0)
			text = move_cursos_down(text);
		if (sfKeyboard_isKeyPressed(sfKeyReturn) && sprite[5]->o_sprt == 0 &&
		    text[2]->pos.y == 375 + (3 * 77))
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyReturn) && sprite[5]->o_sprt == 0 &&
		    text[2]->pos.y == 375 + 77)
			sprite[5]->o_sprt = 1;
		if (sfKeyboard_isKeyPressed(sfKeyS))
			sprite[5]->o_sprt = 5;
		if (event.mouseButton.x >= 1480 &&
		    event.mouseButton.x <= 1680 &&
		    event.mouseButton.y >= 690 &&
		    event.mouseButton.y <= 890)
			sprite[5]->o_sprt = 5;
	}
	return (text);
}

void initialize_sprite2(sprite_t **sprite)
{
	sfVector2f scale = {0.5, 0.5};
	sfVector2f scale2 = {2, 2};

	sprite[1]->r_sprt.top = 10;
	sprite[1]->r_sprt.left = 70;
	sprite[1]->r_sprt.width = 136;
	sprite[1]->r_sprt.height = 183;
	sprite[7]->r_sprt.width = 100;
	sprite[7]->r_sprt.height = 20;
	sprite[7]->v_sprt.x = 40;
	sprite[7]->v_sprt.y = 960;
	sprite[1]->v_sprt.x = 960;
	sprite[1]->v_sprt.y = 540;
	sprite[4]->v_sprt.x = 225 / 2 - 6;
	sprite[4]->v_sprt.y = 213 / 2 - 15;
	sfSprite_setPosition(sprite[4]->s_sprt, sprite[4]->v_sprt);
	sprite[1]->o_sprt = 0;
	sprite[2]->o_sprt = 0;
	sprite[5]->o_sprt = 0;
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	sfSprite_setTextureRect(sprite[7]->s_sprt, sprite[7]->r_sprt);
	sfSprite_setPosition(sprite[1]->s_sprt, sprite[1]->v_sprt);
	sfSprite_setPosition(sprite[7]->s_sprt, sprite[7]->v_sprt);
	sfSprite_setScale(sprite[1]->s_sprt, scale);
	sfSprite_setScale(sprite[7]->s_sprt, scale2);
}

sprite_t **initialize_sprite(sprite_t **sprite)
{
	sfEvent event;

	sprite[0] = malloc(sizeof(sprite_t) * 5);
	sprite[1] = malloc(sizeof(sprite_t) * 5);
	sprite[2] = malloc(sizeof(sprite_t) * 5);
	sprite[3] = malloc(sizeof(sprite_t) * 5);
	sprite[4] = malloc(sizeof(sprite_t) * 5);
	sprite[5] = malloc(sizeof(sprite_t) * 5);
	sprite[6] = malloc(sizeof(sprite_t) * 5);
	sprite[7] = malloc(sizeof(sprite_t) * 5);
	sprite[7] = create_sprite(sprite[7], "rsrc/pictures/life.png");
	sprite[6] = create_sprite(sprite[6], "rsrc/pictures/dlc.png");
	sprite[5] = create_sprite(sprite[5], "rsrc/pictures/pause.png");
	sprite[4] = create_sprite(sprite[4], "rsrc/pictures/minimap_perso.png");
	sprite[3] = create_sprite(sprite[3], "rsrc/pictures/minimap.png");
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

void dlc_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type != sfEvtKeyPressed)
			return;
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sprite[5]->o_sprt = 0;
	}
}
void dlc_loop(sfRenderWindow *window, sprite_t **sprite)
{
	sfEvent event;

	dlc_event(window, event, sprite);
	sfRenderWindow_drawSprite(window, sprite[6]->s_sprt, NULL);
	sfRenderWindow_display(window);
}

void pause_event(sfRenderWindow *window, sfEvent event, sprite_t **sprite)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type != sfEvtKeyPressed)
			return;
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyP) ||
		    sfKeyboard_isKeyPressed(sfKeyEscape) ||
		    sfKeyboard_isKeyPressed(sfKeyR))
			sprite[5]->o_sprt = 1;
	}
}
void pause_loop(sfRenderWindow *window, sprite_t **sprite)
{
	sfEvent event;

	pause_event(window, event, sprite);
	sfRenderWindow_drawSprite(window, sprite[5]->s_sprt, NULL);
	sfRenderWindow_display(window);
}


void game_loop(sfRenderWindow *window, sprite_t **sprite, char **map_txt)
{
	sfEvent event;

	game_event(window, event, sprite, map_txt);
	sfRenderWindow_drawSprite(window, sprite[0]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[1]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[3]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[4]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[7]->s_sprt, NULL);
	if (sprite[2]->o_sprt == 1)
		sfRenderWindow_drawSprite(window, sprite[2]->s_sprt, NULL);
	sfRenderWindow_display(window);
}

char **get_map_txt(void)
{
	char **map_txt = malloc(sizeof(char *) * 310);
	int fd = open("rsrc/map.txt", O_RDONLY);

	if (map_txt == NULL || fd == -1)
		return (NULL);
	for (int i = 0; i < 304; i = i + 2) {
		map_txt[i] = get_next_line(fd);
		map_txt[i + 1] = my_strdup(map_txt[i]);;
	}
	map_txt[305] = NULL;
	return (map_txt);
}

void menu_loop(sfRenderWindow *window)
{
	text_t **text = malloc(sizeof(text_t *) * 5);
	sprite_t *bg = malloc(sizeof(sprite_t));
	sfEvent event;
	sprite_t **sprite = malloc(sizeof(sprite_t *) * 8);
	char **map_txt = get_map_txt();

	sprite = initialize_sprite(sprite);
	text = initialize_text(text);
	text = set_text_value(text);
	bg = create_sprite(bg, "rsrc/pictures/bg.png");
	while (sfRenderWindow_isOpen(window)) {
		if (sprite[5]->o_sprt == 0) {
			text = menu_event(window, event, text, sprite);
			sfRenderWindow_drawSprite(window, bg->s_sprt, NULL);
			disp_text(window, text);
			sfRenderWindow_display(window);
		} else if (sprite[5]->o_sprt == 3) {
			pause_loop(window, sprite);
		} else if (sprite[5]->o_sprt == 5) {
			dlc_loop(window, sprite);
		} else {
			game_loop(window, sprite, map_txt);
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
	sfText_setString(text[2]->text, ">\t\t\t\t\t\t<");
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
	obj = fill_obj_id(obj);
	window = renderwindow_create(window);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfMusic_destroy(music);
	menu_loop(window);
	return (0);
}
