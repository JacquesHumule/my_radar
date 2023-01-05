/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** array_creator.c
*/

#include <math.h>
#include "my.h"
#include "my_radar.h"

static int set_plane(float array[6], plane_t *plane)
{
    if (array == NULL || plane == NULL)
        return EPITECH_FAILURE;
    plane->pos.x = plane->origin.x = array[1];
    plane->pos.y = plane->origin.y = array[0];
    plane->dest.x = array[3];
    plane->dest.y = array[2];
    plane->traveling_distance = sqrtf(powf(plane->dest.x - plane->pos.x, 2) +
        powf(plane->dest.y - plane->pos.y, 2));
    plane->angle = -atan2f(array[2] - array[0], array[3] - array[1]);
    plane->speed.x = cosf(plane->angle) * array[4];
    plane->speed.y = sinf(plane->angle) * array[4];
    plane->norm_speed = array[4];
    plane->takeoff_time = array[5];
    plane->landing_time = plane->traveling_distance / plane->norm_speed +
        plane->takeoff_time;
    plane->landed = plane->crashed = plane->flying = false;
    return EPITECH_SUCCESS;
}

int get_nb_planes(char const *str, plane_t *plane)
{
    str += 2;
    if (check_geo(str) == false) return EPITECH_FAILURE;
    float array[6];
    array[0] = lat_parse(str);
    str++;
    for (; *str != '-' && *str != '+'; str++);
    array[1] = long_parse(str);
    str = my_strstr(str, " ") + 1;
    if (check_geo(str) == false) return EPITECH_FAILURE;
    array[2] = lat_parse(str);
    str++;
    for (; *str != '-' && *str != '+'; str++);
    array[3] = long_parse(str);
    str = my_strstr(str, " ");
    array[4] = (float) my_getnbr(str);
    str = my_strstr(str + 1, " ");
    array[5] = (float) my_getnbr(str);
    set_plane(array, plane);
    return 0;
}

plane_array_t *plane_array_create(linked_list_t *list_plane)
{
    plane_array_t *plane_array = malloc(sizeof(plane_array_t));
    plane_array->size = plane_array->last_stopped = list_plane->len;
    plane_array->planes = malloc(sizeof(plane_t) * list_plane->len);
    for (int i = 0; list_plane != NULL; i++) {
        plane_t *p = &plane_array->planes[i];
        get_nb_planes(list_plane->data, p);
        LT_NEXT(list_plane);
    }
    return plane_array;
}

atc_array_t *atc_array_create(linked_list_t *list_atc)
{
    atc_array_t *atc_array = malloc(sizeof(atc_array_t));
    atc_array->size = list_atc->len;
    atc_array->atc = malloc(sizeof(atc_t) * list_atc->len);
    for (int i = 0; list_atc != NULL; i++) {
        atc_t *a = &atc_array->atc[i];
        char const *str = list_atc->data + 2;
        a->pos.y = lat_parse(str);
        str++;
        for (; *str != '-' && *str != '+'; str++);
        a->pos.x = long_parse(str);
        str = my_strstr(str, " ");
        a->radius = (float) my_getnbr(str);
        LT_NEXT(list_atc);
    }
    return atc_array;
}
