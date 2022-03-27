/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** collision
*/

#ifndef COLLISION_H_
    #define COLLISION_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

player_t *check_collision(player_t *player, game_obj *obj_lis);
void ground_action(player_t *player, sfSprite *object);
void platform_action(player_t *player, sfSprite *object);
int is_click_collision(sfSprite *sprite, sfVector2f mouse);
void enemy_action(player_t *player, sfSprite *object);
#endif /* !COLLISION_H_ */
