/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** action
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

void adjut_player(enum coll_type coll, player_t *player, sfFloatRect run, \
sfFloatRect ground)
{
    sfVector2f pos = {run.left, run.top};

    switch (coll) {
    case TOP:
        pos.y = ground.top + ground.height;
        player->jumpforce = 0;
        break;
    case RIGHT:
        pos.x = ground.left - run.width;
        break;
    case LEFT:
        pos.x = ground.left + ground.width;
        break;
    case BOTTOM:
        pos.y = ground.top - run.height - 1;
        player->state = RUN;
        player->jumpforce = player->save_jf;
    }
    sfSprite_setPosition(player->sprite, pos);
}

void platform_action(player_t *player, sfSprite *object)
{
    sfFloatRect runner = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect ground = sfSprite_getGlobalBounds(object);
    double dx = (runner.left + runner.width) - (ground.left + ground.width);
    double dy = ((runner.top) + runner.height) - (ground.top + ground.height);
    double width = (runner.width + ground.width) / 2;
    double height = (runner.height + ground.height) / 2;

    if ((width * dy) > (height * dx)) {
        if ((width * dy) > - (height * dx)) {
            adjut_player(TOP, player, runner, ground);
        } else
            adjut_player(RIGHT, player, runner, ground);
    } else {
        if ((width * dy) > - (height * dx))
            adjut_player(LEFT, player, runner, ground);
        else {
            adjut_player(BOTTOM, player, runner, ground);
        }
    }
}

void ground_action(player_t *player, sfSprite *object)
{
    sfFloatRect runner = sfSprite_getGlobalBounds(player->sprite);
    sfVector2f ground = sfSprite_getPosition(object);
    double diff = runner.top - ((runner.top + runner.height) - ground.y);
    sfVector2f pos = {runner.left, diff};

    sfSprite_setPosition(player->sprite, pos);
    player->state = RUN;
    player->jumpforce = player->save_jf;
}

void enemy_action(player_t *player, __attribute__((unused)) sfSprite *object)
{
    player->life = 0;
}
