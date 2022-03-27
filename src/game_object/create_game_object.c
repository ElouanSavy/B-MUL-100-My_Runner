/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** create_game_object
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "collision.h"
#include "game_object.h"

game_obj *put_in_gobj_list(game_obj *list, game_obj *element)
{
    element->next = list;
    element->prev = NULL;
    if (list != NULL) {
        list->prev = element;
    }
    list = element;
    return (element);
}

game_obj *create_game_object(game_t *game, void *function, \
enum obj_type type, sfIntRect rect)
{
    game_obj *element = malloc(sizeof(game_obj));

    element->type = type;
    element->action = function;
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, game->texture, sfTrue);
    sfSprite_setTextureRect(element->sprite, rect);
    element = put_in_gobj_list(game->g_object, element);
    return (element);
}

game_obj *init_game_obj(game_t *game)
{
    sfIntRect ground = {0, 2446, 3840, 264};
    game->g_object = NULL;
    sfVector2f pos = {0, 880};

    game->g_object = create_game_object(game, &ground_action, GROUND, ground);
    sfSprite_setPosition(game->g_object->sprite, pos);
    pos.x = 3840;
    game->g_object = create_game_object(game, &ground_action, GROUND, ground);
    sfSprite_setPosition(game->g_object->sprite, pos);
    return (game->g_object);
}

game_obj *add_end_level(game_t *game)
{
    sfIntRect rect = {1921, 518, 153, 164};
    sfVector2f pos = {12188, 716};

    game->g_object = create_game_object(game, enemy_action, WIN, rect);
    sfSprite_setPosition(game->g_object->sprite, pos);
    return (game->g_object);
}

game_obj *remove_end_level(game_t *game)
{
    game->g_object = game->g_object->next;
    return (game->g_object);
}
