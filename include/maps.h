/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** maps
*/

#ifndef MAPS_H_
    #define MAPS_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

maps_t *init_maps(void);
game_obj *map_to_obj(game_t *game, char **map);
#endif /* !MAPS_H_ */
