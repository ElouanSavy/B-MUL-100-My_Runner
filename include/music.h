/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** music
*/

#ifndef MUSIC_H_
    #define MUSIC_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include "my_runner.h"

musics_t init_musics(void);
void play_game_music(game_t *game);
void play_menu_music(game_t *game);
void play_pause_music(game_t *game);
void destroy_music(game_t *game);
void play_hit_sound(game_t *game);
#endif /* !MUSIC_H_ */
