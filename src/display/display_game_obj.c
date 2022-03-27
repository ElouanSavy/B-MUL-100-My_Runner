/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** display_game_obj
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

void display_game_obj(game_t *game)
{
    game_obj *list = game->g_object;

    while (list != NULL) {
        sfRenderWindow_drawSprite(game->window, list->sprite, NULL);
        list = list->next;
    }
}
