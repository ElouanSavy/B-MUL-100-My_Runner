/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** map_to_obj
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

const sfIntRect rect[9] = {{1920, 188, 110, 110}, {1920, 298, 110, 110}, \
{1920, 408, 110, 110}, {2030, 188, 110, 110}, {2140, 188, 110, 110}, \
{2250, 188, 110, 110}, {2030, 298, 110, 110}, {2250, 298, 110, 110}, \
{2250, 408, 110, 110}};

void *get_action(char nbr)
{
    if (nbr != '7')
        return (&platform_action);
    else
        return (&enemy_action);
}

game_obj *convert_line(int row, game_t *game, char *map)
{
    int col = 0;
    sfVector2f pos = {0, 0};

    while (map[col] != '\0') {
        if (map[col] != ' ') {
            game->g_object = create_game_object(game, get_action(map[col]), \
            PLATFORM, rect[map[col] - 49]);
            pos.x = col * 110;
            pos.y = row * 110;
            sfSprite_setPosition(game->g_object->sprite, pos);
        }
        col += 1;
    }
    return (game->g_object);
}

game_obj *map_to_obj(game_t *game, char **map)
{
    for (int i = 0; i < 8; i += 1) {
        game->g_object = convert_line(i, game, map[i]);
    }
    return (game->g_object);
}
