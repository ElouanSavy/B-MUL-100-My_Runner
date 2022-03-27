/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** score
*/

#ifndef SCORE_H_
    #define SCORE_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_runner.h"

score_t init_score(game_t *game);
void display_score(game_t *game);
int score_handler(game_t *game);
void display_score_over(game_t *game);
char *get_best_score(void);
void set_best_score(int score);
void display_best_score(game_t *game);
#endif /* !SCORE_H_ */
