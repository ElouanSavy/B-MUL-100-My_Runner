/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** over_interaction
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "maps.h"
#include "collision.h"
#include "player.h"
#include "game_object.h"
#include "music.h"

void over_interaction(sfMouseButtonEvent mouse, game_t *game)
{
    sfVector2f mouse_pos = {mouse.x, mouse.y};

    if (is_click_collision(game->over->block_1, mouse_pos)) {
        play_hit_sound(game);
        reset_game(game);
    } else if (is_click_collision(game->over->block_2, mouse_pos)) {
        destroy_music(game);
        sfRenderWindow_close(game->window);
    }
}

void rescale_over_block(game_t *game, sfVector2f mouse)
{
    sfVector2f base = {0.64, 0.64};
    sfVector2f upscale = {0.74, 0.74};

    if (is_click_collision(game->over->block_1, mouse)) {
        sfSprite_setScale(game->over->block_1, upscale);
        sfSprite_setScale(game->over->block_2, base);
    } else if (is_click_collision(game->over->block_2, mouse)) {
        sfSprite_setScale(game->over->block_2, upscale);
        sfSprite_setScale(game->over->block_1, base);
    } else {
        sfSprite_setScale(game->over->block_1, base);
        sfSprite_setScale(game->over->block_2, base);
    }
}

void over_animation(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse.x, mouse.y};

    rescale_over_block(game, pos);
}
