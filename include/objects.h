/*
** EPITECH PROJECT, 2022
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
    sfTexture *texture;
    sfClock *clock;
    sfRectangleShape *border;
    sfFloatRect bb;
    sfVector2f origin;
    sfVector2f pos;
    sfVector2f dest;
    sfVector2f speed;
    float norm_speed;
    float traveling_ditance;
    float takeoff_time;
    float landing_time;
    float angle;
    bool landed;
    bool crashed;
    bool flying;
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

typedef struct instance_s {
    sfRenderWindow *window;
    plane_array_t *a_planes;
    atc_array_t *a_atc;
    sfImage *i_plane;
    sfImage *i_atc;
    sfImage *i_map;
    sfTexture *t_map;
    sfSprite *s_map;
    quadtree_t *quadtree;
} instance_t;

#endif //OBJECTS_
