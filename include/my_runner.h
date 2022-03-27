/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myhunter-elouan.savy-camaret
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>

    #define GRAVITY 10

enum gamestate {
    GS_MENU,
    GS_PLAYING,
    GS_OVER,
    GS_PAUSE,
};

enum obj_type {
    BG,
    RUNNER,
    GROUND,
    PLATFORM,
    ENEMY,
    WIN,
};

enum player_state {
    RUN,
    JUMP,
    DASH,
    FALL,
};

enum coll_type {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
};

enum gamemode {
    INFINITE,
    LEVEL,
};

enum music {
    M_PLAY,
    M_PAUSE,
    M_STOP,
};

typedef char *filepath;

typedef struct game_time {
    sfClock *gravity;
    sfClock *clock_bg;
} g_time_t;

typedef struct player {
    enum player_state state;
    int life;
    sfIntRect anim;
    sfSprite *sprite;
    sfClock *clock;
    double jumpforce;
    double save_jf;
} player_t;

typedef struct game_object {
    enum obj_type type;
    sfSprite *sprite;
    void (*action)(player_t *player, sfSprite *object);
    struct game_object *next;
    struct game_object *prev;
} game_obj;

typedef struct bg {
    sfSprite *l1;
    sfSprite *l2;
    sfSprite *l2_2;
} bg_t;

typedef struct menu {
    sfText *title;
    sfText *menu_1;
    sfText *menu_2;
    sfText *menu_3;
    sfSprite *block_1;
    sfSprite *block_2;
    sfSprite *block_3;
} menu_t;

typedef struct pause {
    sfText *title;
    sfText *pause_1;
    sfText *pause_2;
    sfText *pause_3;
    sfSprite *block_1;
    sfSprite *block_2;
    sfSprite *block_3;
} pause_t;

typedef struct over {
    sfText *title;
    sfText *over_1;
    sfText *over_2;
    sfSprite *block_1;
    sfSprite *block_2;
} over_t;

typedef struct maps {
    char **map1;
} maps_t;

typedef struct score {
    sfText *score_txt;
    int count;
} score_t;

typedef struct game_clock {
    sfClock *main_clock;
    sfClock *score_clock;
} game_clock_t;

typedef struct musics {
    sfMusic *menu;
    sfMusic *game;
    sfMusic *hit;
    enum music menu_state;
    enum music game_state;
} musics_t;

typedef struct game {
    sfFont *font;
    enum gamestate state;
    enum gamemode mode;
    struct maps *maps;
    struct bg bg;
    struct game_object *g_object;
    struct game_time time;
    struct player player;
    struct menu *menu;
    struct pause *pause;
    struct over *over;
    struct game_clock game_clock;
    struct score score;
    struct musics musics;
    double gravity;
    sfRectangleShape *rect;
    sfTexture *texture;
    sfRenderWindow *window;
    double game_tick;
} game_t;

sfRenderWindow *create_window(sfVideoMode md, char *name);
sfTexture *create_texture(filepath path);
void window_icon(game_t *game);
void window_resized(sfSizeEvent size, game_t *game);
game_clock_t init_clock(void);
sfText *create_text(sfText *text, char *str, int size, game_t *game);
void game_handler(game_t *game);
void event_handler(game_t *game);
void display_tutorial(void);
char *nb_to_str(long int nb);
void reset_game(game_t *game);
#endif /* !MY_HUNTER_H_ */
