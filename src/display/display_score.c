/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** display_score
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

long int check_nb_size(long int nb)
{
    long int counter = 1;
    long int i = 10;

    while (i <= nb) {
        counter += 1;
        i *= 10;
    }
    return (counter);
}

char *nb_to_str(long int nb)
{
    int size = check_nb_size(nb);
    char *str = malloc(sizeof(char) * (size + 1));
    long int divisor = my_compute_power_rec(10, size) / 10;
    int i = 0;

    if (size == 1) {
        i += 2;
        str[0] = '0';
        str[1] = (nb / divisor) + 48;
    }
    while (i < size) {
        str[i] = (nb / divisor) + 48;
        nb %= divisor;
        divisor /= 10;
        i += 1;
    }
    str[size] = '\0';
    return (str);
}

void display_score(game_t *game)
{
    sfVector2f pos = {16, 16};
    sfFloatRect rect;

    sfText_setString(game->score.score_txt, nb_to_str(game->score.count));
    rect = sfText_getGlobalBounds(game->score.score_txt);
    pos.x = 1920 - 16 - rect.width;
    sfText_setPosition(game->score.score_txt, pos);
    sfRenderWindow_drawText(game->window, game->score.score_txt, NULL);
}
