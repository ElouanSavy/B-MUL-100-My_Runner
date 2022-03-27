/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** pause
*/

#ifndef PAUSE_H_
    #define PAUSE_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

void pause_handler(game_t *game);
pause_t *init_pause(game_t *game);
void pause_interaction(sfMouseButtonEvent mouse, game_t *game);
void pause_animation(game_t *game);
void draw_pause(game_t *game);
#endif /* !PAUSE_H_ */
