/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** play_sound
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"

void play_game_music(game_t *game)
{
    if (game->musics.game_state == M_PLAY)
        return;
    sfMusic_play(game->musics.game);
    sfMusic_stop(game->musics.menu);
    game->musics.game_state = M_PLAY;
    game->musics.menu_state = M_STOP;
}

void play_pause_music(game_t *game)
{
    if (game->musics.menu_state == M_PLAY)
        return;
    sfMusic_play(game->musics.menu);
    sfMusic_pause(game->musics.game);
    game->musics.menu_state = M_PLAY;
    game->musics.game_state = M_PAUSE;
}

void play_menu_music(game_t *game)
{
    if (game->musics.menu_state == M_PLAY)
        return;
    sfMusic_play(game->musics.menu);
    sfMusic_stop(game->musics.game);
    game->musics.menu_state = M_PLAY;
    game->musics.game_state = M_STOP;
}

void play_hit_sound(game_t *game)
{
    sfMusic_stop(game->musics.hit);
    sfMusic_play(game->musics.hit);
}
