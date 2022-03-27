/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** check_collision
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

int is_collision (sfSprite *player, sfSprite *object)
{
    sfFloatRect p_rect = sfSprite_getGlobalBounds(player);
    sfFloatRect obj = sfSprite_getGlobalBounds(object);

    if (obj.left > 1920)
        return (0);
    if (p_rect.left <= (obj.left + obj.width) && p_rect.left \
    + p_rect.width >= obj.left) {
        if (p_rect.top <= (obj.top + obj.height) && p_rect.top \
        + p_rect.height >= obj.top) {
            return (1);
        }
    }
    return (0);
}

player_t *check_collision(player_t *player, game_obj *obj_list)
{
    if (player->state == RUN)
        player->state = FALL;
    while (obj_list->next != NULL)
        obj_list = obj_list->next;
    while (obj_list != NULL) {
        if (is_collision(player->sprite, obj_list->sprite)) {
            obj_list->action(player, obj_list->sprite);
        }
        obj_list = obj_list->prev;
    }
    return (player);
}

int is_click_collision(sfSprite *sprite, sfVector2f mouse)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    if (mouse.x <= (rect.left + rect.width) && mouse.x >= rect.left) {
        if (mouse.y <= (rect.top + rect.height) && mouse.y >= rect.top) {
            return (1);
        }
    }
    return (0);
}
