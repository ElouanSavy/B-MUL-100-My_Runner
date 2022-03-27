/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** pause_handler
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
#include "pause.h"
#include "music.h"

pause_t *init_text_pause(game_t *game, pause_t *pause)
{
    sfVector2f t_pos = {667, 96};
    sfVector2f m1_pos = {911, 423};
    sfVector2f m2_pos = {923, 595};
    sfVector2f m3_pos = {930, 767};

    pause->title = sfText_create();
    pause->pause_1 = sfText_create();
    pause->pause_2 = sfText_create();
    pause->pause_3 = sfText_create();
    pause->title = create_text(pause->title, "Wizard run", 112, game);
    pause->pause_1 = create_text(pause->pause_1, "RESUME", 24, game);
    pause->pause_2 = create_text(pause->pause_2, "MENU", 24, game);
    pause->pause_3 = create_text(pause->pause_3, "QUIT", 24, game);
    sfText_setPosition(pause->title, t_pos);
    sfText_setPosition(pause->pause_1, m1_pos);
    sfText_setPosition(pause->pause_2, m2_pos);
    sfText_setPosition(pause->pause_3, m3_pos);
    return (pause);
}

sfSprite *create_block_pause(game_t *game, sfVector2f pos)
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

pause_t *init_pause(game_t *game)
{
    sfVector2f pos_1 = {960, 446};
    sfVector2f pos_2 = {960, 615};
    sfVector2f pos_3 = {960, 784};
    pause_t *pause = malloc(sizeof(pause_t));

    pause->block_1 = create_block_pause(game, pos_1);
    pause->block_2 = create_block_pause(game, pos_2);
    pause->block_3 = create_block_pause(game, pos_3);
    pause = init_text_pause(game, pause);
    return (pause);
}

void pause_handler(game_t *game)
{
    int time;

    sfClock_restart(game->game_clock.main_clock);
    play_pause_music(game);
    sfRenderWindow_clear(game->window, sfBlack);
    anim_background(game);
    display_bg(game);
    draw_pause(game);
    pause_animation(game);
    event_handler(game);
    time = sfClock_getElapsedTime(game->game_clock.main_clock).microseconds;
    game->game_tick = (double) time / 1000000.00;
}
