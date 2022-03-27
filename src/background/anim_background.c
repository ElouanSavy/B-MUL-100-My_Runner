/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** anim_background
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"

sfSprite *move_layer(sfSprite *l, double v, sfVector2f pos, sfVector2f pos2)
{
    if (pos.x > - 3840) {
        pos.x -= v;
    } else {
        pos.x = pos2.x + 3837;
    }
    sfSprite_setPosition(l, pos);
    return (l);
}

void anim_background(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->bg.l2);
    sfVector2f pos2 = sfSprite_getPosition(game->bg.l2_2);

    move_layer(game->bg.l2, 340 * game->game_tick, pos, pos2);
    move_layer(game->bg.l2_2, 340 * game->game_tick, pos2, pos);
}
