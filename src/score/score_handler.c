/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** score_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

int score_handler(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->game_clock.score_clock);

    if (time.microseconds > 100000) {
        game->score.count += 1;
        sfClock_restart(game->game_clock.score_clock);
    }
    return (0);
}

score_t init_score(game_t *game)
{
    score_t score;

    score.count = 0;
    score.score_txt = sfText_create();
    sfText_setFillColor(score.score_txt, sfWhite);
    sfText_setFont(score.score_txt, game->font);
    sfText_setCharacterSize(score.score_txt, 24);
    return (score);
}

char *get_best_score(void)
{
    FILE *score = fopen("assets/score/score.txt", "r");
    char *buffer = malloc(sizeof(char) * 11);
    int size = fread(buffer, 1, 11, score);

    fclose(score);
    if (size == 0)
        return ("00");
    buffer[size] = '\0';
    return (buffer);
}

void set_best_score(int score)
{
    int current_best = my_getnbr(get_best_score());
    FILE *file;
    char *str;

    if (current_best >= score)
        return;
    str = nb_to_str(score);
    file = fopen("assets/score/score.txt", "w+");
    fwrite(str, 1, my_strlen(str), file);
    fclose(file);
    return;
}
