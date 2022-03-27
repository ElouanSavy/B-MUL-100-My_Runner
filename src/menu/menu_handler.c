/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** menu_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "background.h"
#include "menu.h"
#include "music.h"

sfText *create_text(sfText *text, char *str, int size, game_t *game)
{
    sfColor creame = sfColor_fromRGB(239, 239, 239);

    sfText_setFont(text, game->font);
    sfText_setFillColor(text, creame);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    return (text);
}

menu_t *init_text_menu(game_t *game, menu_t *menu)
{
    sfVector2f t_pos = {667, 96};
    sfVector2f m1_pos = {894, 423};
    sfVector2f m2_pos = {878, 595};
    sfVector2f m3_pos = {931, 767};

    menu->title = sfText_create();
    menu->menu_1 = sfText_create();
    menu->menu_2 = sfText_create();
    menu->menu_3 = sfText_create();
    menu->title = create_text(menu->title, "Wizard run", 112, game);
    menu->menu_1 = create_text(menu->menu_1, "PLAY LEVEL", 24, game);
    menu->menu_2 = create_text(menu->menu_2, "PLAY INFINITE", 24, game);
    menu->menu_3 = create_text(menu->menu_3, "QUIT", 24, game);
    sfText_setPosition(menu->title, t_pos);
    sfText_setPosition(menu->menu_1, m1_pos);
    sfText_setPosition(menu->menu_2, m2_pos);
    sfText_setPosition(menu->menu_3, m3_pos);
    return (menu);
}

sfSprite *create_block_menu(game_t *game, sfVector2f pos)
{
    sfIntRect rect = {1920, 0, 396, 188};
    sfVector2f scale = {0.64, 0.64};
    sfVector2f origin = {198, 94};
    sfSprite *block = sfSprite_create();

    sfSprite_setTexture(block, game->texture, sfTrue);
    sfSprite_setTextureRect(block, rect);
    sfSprite_setOrigin(block, origin);
    sfSprite_setScale(block, scale);
    sfSprite_setPosition(block, pos);
    return (block);
}

menu_t *init_menu(game_t *game)
{
    sfVector2f pos_1 = {960, 446};
    sfVector2f pos_2 = {960, 615};
    sfVector2f pos_3 = {960, 784};
    menu_t *menu = malloc(sizeof(menu_t));

    menu->block_1 = create_block_menu(game, pos_1);
    menu->block_2 = create_block_menu(game, pos_2);
    menu->block_3 = create_block_menu(game, pos_3);
    menu = init_text_menu(game, menu);
    return (menu);
}

void menu_handler(game_t *game)
{
    int time;

    sfClock_restart(game->game_clock.main_clock);
    play_menu_music(game);
    sfRenderWindow_clear(game->window, sfBlack);
    anim_background(game);
    display_bg(game);
    draw_menu(game);
    menu_animation(game);
    event_handler(game);
    time = sfClock_getElapsedTime(game->game_clock.main_clock).microseconds;
    game->game_tick = (double) time / 1000000.00;
}
