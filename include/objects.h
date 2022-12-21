/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** objects.h
*/

#ifndef OBJECTS_
    #define OBJECTS_

    #include <SFML/Graphics.h>
    #include "linked_list.h"

typedef struct plane_s {

} plane_t;

typedef struct atc_s {

} atc_t;

typedef struct instance_s {
    sfRenderWindow *window;
    sfImage *i_plane;
    sfImage *i_atc;
    sfImage *i_map;

} instance_t;

#endif //OBJECTS_
