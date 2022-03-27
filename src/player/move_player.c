/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** move_player
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "player.h"
#include "my.h"
#include "score.h"
#include "game_object.h"
#include "music.h"

void anim_player(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);

    if (time.microseconds > 30000 && player->state == RUN) {
        player->anim.top = 0;
        if (player->anim.left >= 1653)
            player->anim.left = 0;
        else
            player->anim.left += 87;
        sfClock_restart(player->clock);
    }
    if (time.microseconds > 75000 && player->state == JUMP) {
        player->anim.top = 143;
        if (player->anim.left >= 609)
            player->anim.left = 0;
        else
            player->anim.left += 87;
        sfClock_restart(player->clock);
    }
}

void move_player(game_t *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->player.sprite);
    sfVector2f pos = {rect.left, rect.top};

    pos.y += 1150 * game->game_tick;
    sfSprite_setPosition(game->player.sprite, pos);
    sfClock_restart(game->time.gravity);
    if ((rect.left + rect.width < 0) || game->player.life == 0) {
        set_best_score(game->score.count);
        game->state = GS_OVER;
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    }
    if (game->mode == LEVEL) {
        if (sfSprite_getPosition(game->g_object->sprite).x < -300) {
            set_best_score(game->score.count);
            game->state = GS_OVER;
            sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        }
    }
}

void jump_player(game_t *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->player.sprite);
    sfVector2f pos = {rect.left, rect.top};

    if (game->player.state == JUMP) {
        game->player.jumpforce -= 0.2;
        pos.y -= game->player.jumpforce;
        sfSprite_setPosition(game->player.sprite, pos);
    }
}
