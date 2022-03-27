/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

void menu_handler(game_t *game);
menu_t *init_menu(game_t *game);
void menu_interaction(sfMouseButtonEvent mouse, game_t *game);
void menu_animation(game_t *game);
void draw_menu(game_t *game);
#endif /* !MENU_H_ */
