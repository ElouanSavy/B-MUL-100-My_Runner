/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** move_game_obj
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

void move_obj_infinite(game_obj *object, double speed)
{
    sfVector2f pos = sfSprite_getPosition(object->sprite);

    if (object->type == PLATFORM) {
        if (pos.x > - 3840)
            pos.x -= speed;
        else
            pos.x = 8000 - (speed * 3);
    } else {
        if (pos.x > - 3840)
            pos.x -= speed;
        else
            pos.x = 3840 - (speed * 2);
    }
    sfSprite_setPosition(object->sprite, pos);
}

void move_obj_level(game_obj *object, double speed)
{
    sfVector2f pos = sfSprite_getPosition(object->sprite);

    if (object->type == PLATFORM) {
        if (pos.x > - 3840)
            pos.x -= speed;
    } else {
        if (pos.x > - 3840)
            pos.x -= speed;
        else
            pos.x = 3840 - (speed * 2);
    }
    sfSprite_setPosition(object->sprite, pos);
}

void move_game_obj(game_t *game)
{
    game_obj *list = game->g_object;

    while (list != NULL) {
        if (game->mode == INFINITE)
            move_obj_infinite(list, 500 * game->game_tick);
        else if (game->mode == LEVEL)
            move_obj_level(list, 500 * game->game_tick);
        list = list->next;
    }
}
