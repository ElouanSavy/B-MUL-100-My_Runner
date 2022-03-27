/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** display_background
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"

void display_bg(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->bg.l1, NULL);
    sfRenderWindow_drawSprite(game->window, game->bg.l2, NULL);
    sfRenderWindow_drawSprite(game->window, game->bg.l2_2, NULL);
}
