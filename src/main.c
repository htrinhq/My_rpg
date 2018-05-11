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

sprite_t **move_player(sprite_t **sprite, icm_t *icm, int pst)
{
	int y =  (sprite[0]->r_sprt.left - 1260) / 10 + 225;
	int x = (sprite[0]->r_sprt.top - 1480) / 10 + 213;

	detect_chest(x, y, sprite, icm);
	if ((pst == 1 ||pst == 3 ||pst == 5 || pst == 9) && x > 0
	&& icm->map_txt[x - 1][y] == ' ')
		sprite[0]->r_sprt.top -= 10;
	if ((pst == 2 ||pst == 6 ||pst == 10 || pst == 3) && x < 3050
	    && icm->map_txt[x + 1][y] == ' ')
		sprite[0]->r_sprt.top += 10;
	if ((pst == 4 ||pst == 6 ||pst == 5 || pst == 12) && y > 0 &&
	    icm->map_txt[x][y - 1] == ' ')
		sprite[0]->r_sprt.left -= 10;
	if ((pst == 8 ||pst == 10 ||pst == 9 || pst == 14) && y < 4600 &&
	    icm->map_txt[x][y + 1] == ' ')
		sprite[0]->r_sprt.left += 10;
	return (player_animation(sprite, x, y));
}

void game_event2(sfRenderWindow *window, sfEvent event,
		 sprite_t **sprite, icm_t *icm)
{
	int pst = 0;
	if (sprite[2]->o_sprt == 1 && (event.mouseButton.x >= 1332 &&
				       event.mouseButton.x <= (1332 + 250)) &&
	    (event.mouseButton.y >= 747 && event.mouseButton.y <= (747 + 95)) &&
	    sfMouse_isButtonPressed(sfMouseLeft))
		sfRenderWindow_destroy(window);
	if (sprite[2]->o_sprt == 1 && (event.mouseButton.x >= 1605 &&
				       event.mouseButton.x <= (1605 + 250)) &&
	    (event.mouseButton.y >= 747 && event.mouseButton.y <= (747 + 95)) &&
	    sfMouse_isButtonPressed(sfMouseLeft)) {
		sprite[1]->o_sprt = 0;
		sprite[5]->o_sprt = 0;
	}
	if (event.type != sfEvtKeyPressed)
		return;
	if (sprite[14]->o_sprt == 0) {
		if (sfKeyboard_isKeyPressed(sfKeyZ))
			pst += 1;
		if (sfKeyboard_isKeyPressed(sfKeyS))
			pst += 2;
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			pst += 4;
		if (sfKeyboard_isKeyPressed(sfKeyD))
			pst += 8;
		if (pst != 0) {
			move_player(sprite, icm, pst);
			//particules(window, 975, 630, 1);
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyP))
		sprite[5]->o_sprt = 3;
	if (sfKeyboard_isKeyPressed(sfKeyI))
		sprite[2]->o_sprt = (sprite[2]->o_sprt == 0) ? 1 : 0;
	if (sfKeyboard_isKeyPressed(sfKeyE) && sprite[8]->o_sprt == 1) {
		sprite[14]->o_sprt = (sprite[14]->o_sprt == 0) ? 1 : 0;
	}
}

sprite_t **game_event(sfRenderWindow *window, sfEvent event,
		      sprite_t **sprite, icm_t *icm)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		game_event2(window, event, sprite, icm);
	}
	return (sprite);
}

text_t **menu_event(sfRenderWindow *window, sfEvent event, text_t **text,
		sprite_t **sprite)
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

void initialize_sprite2(sprite_t **sprite, plstat_t *stat)
{
	sfVector2f scale = {0.5, 0.5};
	sfVector2f scale2 = {2, 2};
	sfVector2f scale3 = {5, 5};
	int level = (stat->xp % 100) * 8 / 100;

	sprite[1]->r_sprt.top = 10;
	sprite[1]->r_sprt.left = 70;
	sprite[1]->r_sprt.width = 136;
	sprite[1]->r_sprt.height = 183;
	sprite[7]->r_sprt.top = 20 * stat->life;
	sprite[7]->r_sprt.left = 0;
	sprite[7]->r_sprt.width = 100;
	sprite[7]->r_sprt.height = 20;
	sprite[9]->r_sprt.top = 20 * stat->force;
	sprite[9]->r_sprt.left = 0;
	sprite[9]->r_sprt.width = 100;
	sprite[9]->r_sprt.height = 20;
	sprite[10]->r_sprt.top = 20 * stat->inteligence;
	sprite[10]->r_sprt.left = 0;
	sprite[10]->r_sprt.width = 100;
	sprite[10]->r_sprt.height = 20;
	sprite[11]->r_sprt.top = 20 * stat->speed;
	sprite[11]->r_sprt.left = 0;
	sprite[11]->r_sprt.width = 100;
	sprite[11]->r_sprt.height = 20;
	sprite[12]->r_sprt.top = 20 * level;
	sprite[12]->r_sprt.left = 0;
	sprite[12]->r_sprt.width = 100;
	sprite[12]->r_sprt.height = 20;
	sprite[16]->r_sprt.top = 10;
	sprite[16]->r_sprt.left = 70;
	sprite[16]->r_sprt.width = 136;
	sprite[16]->r_sprt.height = 183;
	sprite[16]->v_sprt.x = 198;
	sprite[16]->v_sprt.y = 42;
	sprite[7]->v_sprt.x = 40;
	sprite[7]->v_sprt.y = 960;
	sprite[1]->v_sprt.x = 960;
	sprite[1]->v_sprt.y = 540;
	sprite[4]->v_sprt.x = 225 / 2 - 6;
	sprite[4]->v_sprt.y = 213 / 2 - 15;
	sprite[8]->v_sprt.x = 960;
	sprite[8]->v_sprt.y = 440;
	sprite[9]->v_sprt.x = 700;
	sprite[9]->v_sprt.y = 350;
	sprite[10]->v_sprt.x = 700;
	sprite[10]->v_sprt.y = 450;
	sprite[11]->v_sprt.x = 700;
	sprite[11]->v_sprt.y = 550;
	sprite[12]->v_sprt.x = 700;
	sprite[12]->v_sprt.y = 650;
	sprite[13]->v_sprt.x = 730;
	sprite[13]->v_sprt.y = 650;
	sprite[1]->o_sprt = 0;
	sprite[2]->o_sprt = 0;
	sprite[5]->o_sprt = 0;
	sprite[8]->o_sprt = 0;
	sprite[9]->o_sprt = 0;
	sprite[14]->o_sprt = 0;
	sfSprite_setTextureRect(sprite[0]->s_sprt, sprite[0]->r_sprt);
	sfSprite_setTextureRect(sprite[1]->s_sprt, sprite[1]->r_sprt);
	sfSprite_setTextureRect(sprite[7]->s_sprt, sprite[7]->r_sprt);
	sfSprite_setTextureRect(sprite[9]->s_sprt, sprite[9]->r_sprt);
	sfSprite_setTextureRect(sprite[10]->s_sprt, sprite[10]->r_sprt);
	sfSprite_setTextureRect(sprite[11]->s_sprt, sprite[11]->r_sprt);
	sfSprite_setTextureRect(sprite[12]->s_sprt, sprite[12]->r_sprt);
	sfSprite_setTextureRect(sprite[16]->s_sprt, sprite[16]->r_sprt);
	sfSprite_setPosition(sprite[1]->s_sprt, sprite[1]->v_sprt);
	sfSprite_setPosition(sprite[7]->s_sprt, sprite[7]->v_sprt);
	sfSprite_setPosition(sprite[8]->s_sprt, sprite[8]->v_sprt);
	sfSprite_setPosition(sprite[9]->s_sprt, sprite[9]->v_sprt);
	sfSprite_setPosition(sprite[10]->s_sprt, sprite[10]->v_sprt);
	sfSprite_setPosition(sprite[11]->s_sprt, sprite[11]->v_sprt);
	sfSprite_setPosition(sprite[12]->s_sprt, sprite[12]->v_sprt);
	sfSprite_setPosition(sprite[16]->s_sprt, sprite[16]->v_sprt);
	sfSprite_setScale(sprite[1]->s_sprt, scale);
	sfSprite_setScale(sprite[7]->s_sprt, scale2);
	sfSprite_setScale(sprite[8]->s_sprt, scale2);
	sfSprite_setScale(sprite[9]->s_sprt, scale3);
	sfSprite_setScale(sprite[10]->s_sprt, scale3);
	sfSprite_setScale(sprite[11]->s_sprt, scale3);
	sfSprite_setScale(sprite[12]->s_sprt, scale3);
	sfSprite_setScale(sprite[16]->s_sprt, scale);
	sprite[13]->text = sfText_create();
	sprite[13]->font = sfFont_createFromFile("rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfText_setFont(sprite[13]->text, sprite[13]->font);
	sfText_setPosition(sprite[13]->text, sprite[13]->v_sprt);
	sfText_setCharacterSize(sprite[13]->text, 70);
}

sprite_t **initialize_sprite(sprite_t **sprite, plstat_t *stat)
{
	sprite[0] = malloc(sizeof(sprite_t) * 5);
	sprite[1] = malloc(sizeof(sprite_t) * 5);
	sprite[2] = malloc(sizeof(sprite_t) * 5);
	sprite[3] = malloc(sizeof(sprite_t) * 5);
	sprite[4] = malloc(sizeof(sprite_t) * 5);
	sprite[5] = malloc(sizeof(sprite_t) * 5);
	sprite[6] = malloc(sizeof(sprite_t) * 5);
	sprite[7] = malloc(sizeof(sprite_t) * 5);
	sprite[8] = malloc(sizeof(sprite_t) * 5);
	sprite[9] = malloc(sizeof(sprite_t) * 5);
	sprite[10] = malloc(sizeof(sprite_t) * 5);
	sprite[11] = malloc(sizeof(sprite_t) * 5);
	sprite[12] = malloc(sizeof(sprite_t) * 5);
	sprite[13] = malloc(sizeof(sprite_t) * 5);
	sprite[14] = malloc(sizeof(sprite_t) * 5);
	sprite[15] = malloc(sizeof(sprite_t) * 5);
	sprite[16] = malloc(sizeof(sprite_t) * 5);
	sprite[16] = create_sprite(sprite[16], "rsrc/pictures/gardian.png");
	sprite[15] = create_sprite(sprite[15], "rsrc/pictures/timeout.png");
	sprite[14] = create_sprite(sprite[14], "rsrc/pictures/chest.png");
	sprite[13]->text = sfText_create();
	sprite[12] = create_sprite(sprite[12], "rsrc/pictures/level.png");
	sprite[11] = create_sprite(sprite[11], "rsrc/pictures/speed.png");
	sprite[10] = create_sprite(sprite[10], "rsrc/pictures/inteligence.png");
	sprite[9] = create_sprite(sprite[9], "rsrc/pictures/force.png");
	sprite[8] = create_sprite(sprite[8], "rsrc/pictures/openchest.png");
	sprite[7] = create_sprite(sprite[7], "rsrc/pictures/life.png");
	sprite[6] = create_sprite(sprite[6], "rsrc/pictures/dlc.png");
	sprite[5] = create_sprite(sprite[5], "rsrc/pictures/pause.png");
	sprite[4] = create_sprite(sprite[4], "rsrc/pictures/minimap_perso.png");
	sprite[3] = create_sprite(sprite[3], "rsrc/pictures/minimap.png");
	sprite[2] = create_sprite(sprite[2], "rsrc/pictures/inventory.png");
	sprite[1] = create_sprite(sprite[1], "rsrc/pictures/p1.png");
	sprite[0] = create_sprite(sprite[0], "rsrc/pictures/map.png");
	sprite[0]->clock = sfClock_create();
	sprite[0]->r_sprt.top = 1480;
	sprite[0]->r_sprt.left = 1260;
	sprite[0]->r_sprt.width = 1920;
	sprite[0]->r_sprt.height = 1080;
	sprite[0]->text = sfText_create();
	sprite[0]->font = sfFont_createFromFile("./rsrc/fonts/copyfonts.com_algol-ix.ttf");
	sfText_setFont(sprite[0]->text, sprite[0]->font);
	sfText_setCharacterSize(sprite[0]->text, 90);
	sfText_setColor(sprite[0]->text, sfColor_fromRGB(255, 255, 255));
	sfText_setPosition(sprite[0]->text, (sfVector2f){880, 0});
	initialize_sprite2(sprite, stat);
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

void game_loop(sfRenderWindow *window, sprite_t **sprite, icm_t *icm,
	plstat_t *stat)
{
	sfEvent event;

	sfRenderWindow_drawSprite(window, sprite[0]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[1]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[3]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[4]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[7]->s_sprt, NULL);
	sfRenderWindow_drawSprite(window, sprite[16]->s_sprt, NULL);
	sprite[16]->v_sprt.x = 198;
	sprite[16]->v_sprt.y = 42;
	sprite[16]->v_sprt.x = sprite[16]->v_sprt.x * 9.8- sprite[0]->r_sprt.left;
	sprite[16]->v_sprt.y = sprite[16]->v_sprt.y * 18.5 - sprite[0]->r_sprt.top;
	sfSprite_setPosition(sprite[16]->s_sprt, sprite[16]->v_sprt);
	if (sprite[2]->o_sprt == 1) {
		sfRenderWindow_drawSprite(window, sprite[2]->s_sprt, NULL);
		display_stat(sprite, window, stat);
	}
	if (sprite[8]->o_sprt == 1)
		sfRenderWindow_drawSprite(window, sprite[8]->s_sprt, NULL);
	if (sprite[14]->o_sprt == 1 && sprite[8]->o_sprt == 1) {
		sfRenderWindow_drawSprite(window, sprite[14]->s_sprt, NULL);
		display_chest(sprite[14]->v_sprt.x, sprite[14]->v_sprt.y, icm, window);
	}
	display_npc(window, sprite[0]->r_sprt);
	day_time(window, sprite);
	game_event(window, event, sprite, icm);
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

void menu_loop(sfRenderWindow *window, icm_t *icm)
{
	text_t **text = malloc(sizeof(text_t *) * 5);
	sprite_t *bg = malloc(sizeof(sprite_t));
	sfEvent event;
	sprite_t **sprite = malloc(sizeof(sprite_t *) * 17);
	plstat_t *stat = malloc(sizeof(plstat_t));

	icm->map_txt = get_map_txt();
	initialize_stat(stat);
	sprite = initialize_sprite(sprite, stat);
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
			game_loop(window, sprite, icm, stat);
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
//	text[0]->bo = 0;
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

void initialize_stat(plstat_t *stat)
{
	stat->force = 1;
	stat->inteligence = 1;
	stat->speed = 1;
	stat->xp = 165;
	stat->life = 5;
}

int main(int argc, char **argv, char**envp)
{
	sfRenderWindow *window = NULL;
	sfMusic *music;
	icm_t *icm = malloc(sizeof(icm_t));

	icm->obj = malloc(sizeof(idobj_t *) * 16);
	icm->s_obj = malloc(sizeof(sprite_t *) * 15);
	//icm->inventory = malloc(sizeof(int) * 17);
	//icm->inventory = create_inventory(icm->inventory);
	icm->chests = create_chests(icm->chests);
	icm->s_obj = fill_obj_sprite(icm->s_obj);
	if (check_env(envp) == 84 || argc != 1 || argv == NULL)
		return (84);
	init_var();
	music = sfMusic_createFromFile("rsrc/sounds/main.ogg");
	sfMusic_play(music);
	icm->obj = fill_obj_id(icm->obj);
	window = renderwindow_create(window);
	sfRenderWindow_setFramerateLimit(window, 60);
	menu_loop(window, icm);
	sfMusic_destroy(music);
	return (0);
}
