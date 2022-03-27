/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** window_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Export.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"

sfRenderWindow *create_window(sfVideoMode md, char *name)
{
    sfRenderWindow *window;
    sfUint32 flags = sfClose | sfResize;
    sfVideoMode dk = sfVideoMode_getDesktopMode();
    sfVector2i pos;

    pos.x = (dk.width / 2) - (md.width / 2);
    pos.y = (dk.height / 2) - (md.height / 2);
    window = sfRenderWindow_create(md, name, flags, NULL);
    sfRenderWindow_setPosition(window, pos);
    return (window);
}

void window_resized(sfSizeEvent size, game_t *game)
{
    sfFloatRect viewport = {0, 0, size.width, size.height};

    sfRenderWindow_setView(game->window, sfView_createFromRect(viewport));
}

void window_icon(game_t *game)
{
    sfImage *icon = sfImage_createFromFile("assets/icon/icon.png");

    sfRenderWindow_setIcon(game->window, 32, 32, sfImage_getPixelsPtr(icon));
}
