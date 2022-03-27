/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** music_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"

musics_t init_musics(void)
{
    musics_t musics;

    musics.menu = sfMusic_createFromFile("assets/musics/menu.ogg");
    musics.game = sfMusic_createFromFile("assets/musics/game.ogg");
    musics.hit = sfMusic_createFromFile("assets/musics/hit.ogg");
    sfMusic_setVolume(musics.menu, 100.0);
    sfMusic_setVolume(musics.game, 90.0);
    sfMusic_setVolume(musics.hit, 40.0);
    sfMusic_setLoop(musics.menu, sfTrue);
    sfMusic_setLoop(musics.game, sfTrue);
    musics.menu_state = M_STOP;
    musics.game_state = M_STOP;
    return (musics);
}

void destroy_music(game_t *game)
{
    sfMusic_destroy(game->musics.menu);
    sfMusic_destroy(game->musics.game);
    sfMusic_destroy(game->musics.hit);
}
