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
    sfRectangleShape *hitbox;
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
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfVector2f size;
} atc_t;

typedef struct atc_array_s {
    atc_t *atc;
    int size;
} atc_array_t;

typedef struct instance_s {
    sfRenderWindow *window;
    plane_array_t *planes;
    atc_array_t *atc;
    sfImage *i_plane;
    sfImage *i_atc;
    sfImage *i_map;
    sfSprite *s_map;
} instance_t;
#endif //OBJECTS_
