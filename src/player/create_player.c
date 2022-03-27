/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** create_player
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

void reset_player_pos(game_t *game)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    sfVector2f pos = {win_size.x * 0.1, win_size.y * 0.3};

    sfSprite_setPosition(game->player.sprite, pos);
}

player_t create_player(game_t game)
{
    player_t player;
    sfIntRect tmp = {0, 0, 87, 140};
    sfVector2f scale = {0.78, 0.78};
    sfVector2u win_size = sfRenderWindow_getSize(game.window);
    sfVector2f pos = {win_size.x * 0.1, win_size.y * 0.3};

    player.sprite = sfSprite_create();
    player.clock = sfClock_create();
    player.life = 1;
    player.anim = tmp;
    player.jumpforce = 20.5;
    player.save_jf = 20.5;
    player.state = RUN;
    sfSprite_setScale(player.sprite, scale);
    sfSprite_setTexture(player.sprite, game.texture, sfTrue);
    sfSprite_setPosition(player.sprite, pos);
    return (player);
}
