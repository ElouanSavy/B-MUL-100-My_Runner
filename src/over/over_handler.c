/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** over_handler
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
#include "score.h"
#include "over.h"
#include "music.h"

over_t *init_text_over(game_t *game, over_t *over)
{
    sfVector2f t_pos = {667, 96};
    sfVector2f m1_pos = {891, 489};
    sfVector2f m2_pos = {931, 661};

    over->title = sfText_create();
    over->over_1 = sfText_create();
    over->over_2 = sfText_create();
    over->title = create_text(over->title, "Wizard run", 112, game);
    over->over_1 = create_text(over->over_1, "PLAY AGAIN", 24, game);
    over->over_2 = create_text(over->over_2, "QUIT", 24, game);
    sfText_setPosition(over->title, t_pos);
    sfText_setPosition(over->over_1, m1_pos);
    sfText_setPosition(over->over_2, m2_pos);
    return (over);
}

over_t *init_block_over(game_t *game, over_t *over)
{
    sfIntRect rect = {1920, 0, 396, 188};
    sfVector2f scale = {0.64, 0.64};
    sfVector2f pos_1 = {960, 512};
    sfVector2f pos_2 = {960, 681};
    sfVector2f origin = {198, 94};

    over->block_1 = sfSprite_create();
    over->block_2 = sfSprite_create();
    sfSprite_setTexture(over->block_1, game->texture, sfTrue);
    sfSprite_setTexture(over->block_2, game->texture, sfTrue);
    sfSprite_setTextureRect(over->block_1, rect);
    sfSprite_setTextureRect(over->block_2, rect);
    sfSprite_setOrigin(over->block_1, origin);
    sfSprite_setOrigin(over->block_2, origin);
    sfSprite_setScale(over->block_1, scale);
    sfSprite_setScale(over->block_2, scale);
    sfSprite_setPosition(over->block_1, pos_1);
    sfSprite_setPosition(over->block_2, pos_2);
    return (over);
}

over_t *init_over(game_t *game)
{
    over_t *over = malloc(sizeof(over_t));

    over = init_text_over(game, over);
    over = init_block_over(game, over);
    return (over);
}

void over_handler(game_t *game)
{
    int time;

    sfClock_restart(game->game_clock.main_clock);
    play_menu_music(game);
    sfRenderWindow_clear(game->window, sfBlack);
    event_handler(game);
    anim_background(game);
    display_bg(game);
    sfRenderWindow_drawRectangleShape(game->window, game->rect, NULL);
    sfRenderWindow_drawText(game->window, game->over->title, NULL);
    sfRenderWindow_drawSprite(game->window, game->over->block_1, NULL);
    sfRenderWindow_drawSprite(game->window, game->over->block_2, NULL);
    sfRenderWindow_drawText(game->window, game->over->over_1, NULL);
    sfRenderWindow_drawText(game->window, game->over->over_2, NULL);
    over_animation(game);
    display_score_over(game);
    display_best_score(game);
    sfRenderWindow_display(game->window);
    time = sfClock_getElapsedTime(game->game_clock.main_clock).microseconds;
    game->game_tick = (double) time / 1000000.00;
}
