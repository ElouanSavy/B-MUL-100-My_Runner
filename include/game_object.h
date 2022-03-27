/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** game_object
*/

#ifndef GAME_OBJECT_H_
    #define GAME_OBJECT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

game_obj *init_game_obj(game_t *game);
void move_game_obj(game_t *game);
game_obj *create_game_object(game_t *game, void *function, \
enum obj_type type, sfIntRect rect);
game_obj *destroy_game_obj(game_t *game);
void display_game_obj(game_t *game);
void clear_go_list(game_t *game);
game_obj *add_end_level(game_t *game);
game_obj *remove_end_level(game_t *game);
game_obj *free_game_obj(game_obj *item);
#endif /* !GAME_OBJECT_H_ */
