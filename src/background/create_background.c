/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** create_background
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"

sfSprite *create_layer(sfTexture *texture, sfSprite *sprite)
{
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

bg_t create_background(sfTexture *texture)
{
    bg_t bg;
    sfIntRect bg_l1 = {0, 286, 1920, 1080};
    sfIntRect bg_l2 = {0, 1366, 3840, 1080};
    sfVector2f pos = {3840, 0};

    bg.l1 = create_layer(texture, bg.l1);
    bg.l2 = create_layer(texture, bg.l2);
    bg.l2_2 = create_layer(texture, bg.l2_2);
    sfSprite_setTextureRect(bg.l1, bg_l1);
    sfSprite_setTextureRect(bg.l2, bg_l2);
    sfSprite_setTextureRect(bg.l2_2, bg_l2);
    sfSprite_setPosition(bg.l2_2, pos);
    return (bg);
}
