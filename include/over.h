/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** over
*/

#ifndef OVER_H_
    #define OVER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

void over_handler(game_t *game);
over_t *init_over(game_t *game);
void over_interaction(sfMouseButtonEvent mouse, game_t *game);
void over_animation(game_t *game);
#endif /* !OVER_H_ */
