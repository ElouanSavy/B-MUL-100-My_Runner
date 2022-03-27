/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** game_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "player.h"
#include "collision.h"
#include "background.h"
#include "game_object.h"
#include "score.h"
#include "maps.h"
#include "music.h"

void reset_game(game_t *game)
{
    if (game->g_object != NULL)
            clear_go_list(game);
    init_game_obj(game);
    map_to_obj(game, game->maps->map1);
    if (game->mode == LEVEL)
        add_end_level(game);
    reset_player_pos(game);
    game->score.count = 0;
    game->state = GS_PLAYING;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->player.life = 1;
}

void update_items(game_t *game)
{
    move_game_obj(game);
    move_player(game);
    jump_player(game);
    check_collision(&game->player, game->g_object);
    event_handler(game);
    score_handler(game);
}

void game_handler(game_t *game)
{
    int time;

    sfClock_restart(game->game_clock.main_clock);
    play_game_music(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_bg(game);
    anim_background(game);
    display_player(game);
    display_game_obj(game);
    display_score(game);
    update_items(game);
    sfRenderWindow_display(game->window);
    time = sfClock_getElapsedTime(game->game_clock.main_clock).microseconds;
    game->game_tick = (double) time / 1000000.00;
}
