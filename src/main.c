/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "player.h"
#include "my.h"
#include "background.h"
#include "menu.h"
#include "maps.h"
#include "game_object.h"
#include "score.h"
#include "over.h"
#include "pause.h"
#include "music.h"

sfRectangleShape *init_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor black = sfColor_fromRGBA(0, 0, 0, 102);
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 1080};

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, black);
    return (rect);
}

void check_gs(game_t *game)
{
    switch (game->state) {
    case GS_MENU:
        menu_handler(game);
        break;
    case GS_PLAYING:
        game_handler(game);
        break;
    case GS_OVER:
        over_handler(game);
        break;
    case GS_PAUSE:
        pause_handler(game);
    default:
        break;
    }
}

void init_all_screens(game_t *game)
{
    game->menu = init_menu(game);
    game->over = init_over(game);
    game->pause = init_pause(game);
}

game_t init_game(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};

    game->window = create_window(mode, "my_runner");
    game->texture = create_texture("assets/sprites/sprite_sheet.png");
    game->player = create_player(*game);
    game->state = GS_MENU;
    game->time.gravity = sfClock_create();
    game->bg = create_background(game->texture);
    game->g_object = init_game_obj(game);
    game->rect = init_rect();
    game->font = sfFont_createFromFile("assets/font/Lato/Lato-Black.ttf");
    game->maps = init_maps();
    init_all_screens(game);
    game->g_object = map_to_obj(game, game->maps->map1);
    game->game_clock = init_clock();
    game->game_tick = 0.016666;
    game->score = init_score(game);
    game->musics = init_musics();
    return (*game);
}

int main(int argc, char **argv, char **env)
{
    game_t game;

    if (!env[50])
        return (84);
    if (argc > 1 && !my_strcmp(argv[1], "-h")) {
        display_tutorial();
        return (0);
    }
    game = init_game(&game);
    sfRenderWindow_setFramerateLimit(game.window, 120);
    window_icon(&game);
    while (sfRenderWindow_isOpen(game.window))
        check_gs(&game);
    return (0);
}
