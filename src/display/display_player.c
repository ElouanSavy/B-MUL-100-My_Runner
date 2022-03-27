/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** display_sprites
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "player.h"

void display_player(game_t *game)
{
    anim_player(&game->player);
    sfSprite_setTextureRect(game->player.sprite, game->player.anim);
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
}
