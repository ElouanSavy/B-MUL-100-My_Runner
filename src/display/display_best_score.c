/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** display_best_score
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "score.h"

void display_score_over(game_t *game)
{
    sfText *caption = sfText_create();
    sfText *score = sfText_create();
    sfVector2f cap_pos = {755, 294};
    sfVector2f score_pos = {807, 333};

    caption = create_text(caption, "SCORE", 32, game);
    score = create_text(score, nb_to_str(game->score.count), 32, game);
    sfText_setPosition(caption, cap_pos);
    score_pos.x -= sfText_getGlobalBounds(score).width / 2;
    sfText_setPosition(score, score_pos);
    sfRenderWindow_drawText(game->window, score, NULL);
    sfRenderWindow_drawText(game->window, caption, NULL);
    sfText_destroy(caption);
    sfText_destroy(score);
}

void display_best_score(game_t *game)
{
    sfText *caption = sfText_create();
    sfText *score = sfText_create();
    sfVector2f cap_pos = {988, 294};
    sfVector2f score_pos = {1081, 333};

    caption = create_text(caption, "BEST SCORE", 32, game);
    score = create_text(score, get_best_score(), 32, game);
    sfText_setPosition(caption, cap_pos);
    score_pos.x -= sfText_getGlobalBounds(score).width / 2;
    sfText_setPosition(score, score_pos);
    sfRenderWindow_drawText(game->window, score, NULL);
    sfRenderWindow_drawText(game->window, caption, NULL);
    sfText_destroy(caption);
    sfText_destroy(score);
}
