/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

player_t create_player(game_t game);
void anim_player(player_t *player);
void display_player(game_t *game);
void jump_player(game_t *game);
void move_player(game_t *game);
void reset_player_pos(game_t *game);
#endif /* !PLAYER_H_ */
