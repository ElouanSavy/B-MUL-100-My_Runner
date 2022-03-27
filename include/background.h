/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** background
*/

#ifndef BACKGROUND__H_
    #define BACKGROUND__H_

    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

sfSprite *move_layer(sfSprite *l, double v, sfVector2f pos, sfVector2f pos2);
void anim_background(game_t *game);
bg_t create_background(sfTexture *texture);
void display_bg(game_t *game);
#endif /* !BACKGROUND__H_ */
