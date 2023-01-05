/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** objects.h
*/

#ifndef OBJECTS_
    #define OBJECTS_
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "linked_list.h"

typedef struct plane_s {
    sfSprite *sprite;
    sfClock *clock;
    sfRectangleShape *border;
    sfFloatRect bb;
    sfVector2f origin;
    sfVector2f pos;
    sfVector2f dest;
    sfVector2f speed;
    float norm_speed;
    float traveling_distance;
    float takeoff_time;
    float landing_time;
    float angle;
    bool landed : 1;
    bool crashed : 1;
    bool flying : 1;
} plane_t;

typedef struct plane_array_s {
    plane_t *planes;
    size_t size;
    size_t last_stopped;
} plane_array_t;

typedef struct atc_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfCircleShape *border;
    sfVector2f pos;
    float radius;
} atc_t;

typedef struct atc_array_s {
    atc_t *atc;
    int size;
} atc_array_t;

typedef struct quadtree_s {
    plane_t **planes;
    struct quadtree_s *childs[4];
    sfFloatRect bb;
    sfRectangleShape *display;
    size_t nb_planes;
} quadtree_t;

enum child {
    TL,
    TR,
    BL,
    BR
};

typedef struct states_s {
    bool show_quatree : 1;
    bool show_clock : 1;
    bool show_planes : 1;
    bool show_pbb : 1;
    bool show_atc : 1;
    bool show_atc_area : 1;
} states_t;

typedef struct instance_s {
    sfRenderWindow *window;
    plane_array_t *a_planes;
    atc_array_t *a_atc;
    sfTexture *t_plane;
    sfTexture *t_atc;
    sfTexture *t_map;
    sfSprite *s_map;
    quadtree_t *quadtree;
    sfText *clock;
    sfClock *clock_time;
    sfFont *font;
    states_t states;
} instance_t;

#endif //OBJECTS_
