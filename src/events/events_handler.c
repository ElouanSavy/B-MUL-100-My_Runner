/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** events_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "menu.h"
#include "over.h"
#include "pause.h"
#include "music.h"

void quit_game(game_t *game)
{
    destroy_music(game);
    sfRenderWindow_close(game->window);
}

void click_handler(sfMouseButtonEvent mouse, game_t *game)
{
    if (game->state == GS_MENU && mouse.button == sfMouseLeft) {
        menu_interaction(mouse, game);
    }
    if (game->state == GS_OVER && mouse.button == sfMouseLeft) {
        over_interaction(mouse, game);
    }
    if (game->state == GS_PAUSE && mouse.button == sfMouseLeft) {
        pause_interaction(mouse, game);
    }
}

void key_handler(sfKeyEvent key, game_t *game)
{
    if (game->state == GS_PLAYING) {
        if (key.code == sfKeySpace && game->player.state == RUN)
            game->player.state = JUMP;
        if (key.code == sfKeyEscape) {
            sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
            game->state = GS_PAUSE;
        }
    }
}

void event_handler(game_t *game)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            quit_game(game);
            break;
        case sfEvtResized:
            window_resized(event.size, game);
            break;
        case sfEvtMouseButtonPressed:
            click_handler(event.mouseButton, game);
            break;
        case sfEvtKeyPressed:
            key_handler(event.key, game);
            break;
        default:
            break;
        }
    }
}
