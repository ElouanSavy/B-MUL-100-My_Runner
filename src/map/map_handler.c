/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-elouan.savy-camaret
** File description:
** map_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_runner.h"
#include "my.h"

char **map_to_tab(filepath path)
{
    char **map_tab = malloc(sizeof(char *) * 9);
    FILE *file_map = NULL;

    file_map = fopen(path, "r");
    map_tab[8] = NULL;
    for (int i = 0; i < 8; i += 1) {
        map_tab[i] = malloc(sizeof(char) * 109);
        fread(map_tab[i], 1, 109, file_map);
        map_tab[i][108] = '\0';
    }
    fclose(file_map);
    return (map_tab);
}

maps_t *init_maps(void)
{
    maps_t *maps = malloc(sizeof(maps_t));

    maps->map1 = map_to_tab("assets/maps/map_1.txt");
    return (maps);
}
