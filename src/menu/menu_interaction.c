/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** menu_interaction
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"
#include "collision.h"
#include "game_object.h"
#include "music.h"

void launch_game(game_t *game)
{
    game->state = GS_PLAYING;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->player.life = 1;
}

void draw_menu(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window, game->rect, NULL);
    sfRenderWindow_drawText(game->window, game->menu->title, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->block_1, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->block_2, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->block_3, NULL);
    sfRenderWindow_drawText(game->window, game->menu->menu_1, NULL);
    sfRenderWindow_drawText(game->window, game->menu->menu_2, NULL);
    sfRenderWindow_drawText(game->window, game->menu->menu_3, NULL);
    sfRenderWindow_display(game->window);
}

void menu_interaction(sfMouseButtonEvent mouse, game_t *game)
{
    sfVector2f mouse_pos = {mouse.x, mouse.y};

    if (is_click_collision(game->menu->block_3, mouse_pos)) {
        destroy_music(game);
        sfRenderWindow_close(game->window);
    }
    if (is_click_collision(game->menu->block_1, mouse_pos)) {
        play_hit_sound(game);
        if (game->g_object->type != WIN)
            add_end_level(game);
        game->mode = LEVEL;
        launch_game(game);
    }
    if (is_click_collision(game->menu->block_2, mouse_pos)) {
        play_hit_sound(game);
        if (game->g_object->type == WIN)
            remove_end_level(game);
        game->mode = INFINITE;
        launch_game(game);
    }
}

void rescale_block(game_t *game, sfVector2f mouse)
{
    sfVector2f base = {0.64, 0.64};
    sfVector2f upscale = {0.70, 0.70};

    if (is_click_collision(game->menu->block_1, mouse))
        sfSprite_setScale(game->menu->block_1, upscale);
    else
        sfSprite_setScale(game->menu->block_1, base);
    if (is_click_collision(game->menu->block_2, mouse))
        sfSprite_setScale(game->menu->block_2, upscale);
    else
        sfSprite_setScale(game->menu->block_2, base);
    if (is_click_collision(game->menu->block_3, mouse))
        sfSprite_setScale(game->menu->block_3, upscale);
    else
        sfSprite_setScale(game->menu->block_3, base);
}

void menu_animation(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse.x, mouse.y};

    rescale_block(game, pos);
}
