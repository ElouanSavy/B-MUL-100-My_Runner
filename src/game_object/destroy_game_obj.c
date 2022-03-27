/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** destroy_game_obj
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

game_obj *free_game_obj(game_obj *item)
{
    game_obj *list = item->next;

    sfSprite_destroy(item->sprite);
    free(item);
    return (list);
}

game_obj *destroy_game_obj(game_t *game)
{
    game_obj *list = game->g_object;
    sfFloatRect rect;
    game_obj *save;

    while (list != NULL) {
        rect = sfSprite_getGlobalBounds(list->sprite);
        if (rect.left + rect.width < 0 && list->type == PLATFORM) {
            save = list;
            list = list->next;
            save->prev->next = list;
            list->prev = save->prev;
            free_game_obj(save);
        } else
            list = list->next;
    }
    return (game->g_object);
}

void clear_go_list(game_t *game)
{
    game_obj *list = game->g_object;

    while (list != NULL) {
        list = free_game_obj(list);
    }
    game->g_object = NULL;
}
