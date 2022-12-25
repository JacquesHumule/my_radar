/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** opener.c
*/

#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "linked_list.h"
#include "objects.h"
#include "my_radar.h"
#define IS_NUM(x) (x >= '0' && x <= '9')

static int set_plane(float array[6], plane_t *plane)
{
    if (array == NULL || plane == NULL)
        return EPITECH_FAILURE;
    plane->pos.x = plane->origin.x = array[1];
    plane->pos.y = plane->origin.y = array[0];
    plane->dest.x = array[3];
    plane->dest.y = array[2];
    plane->traveling_ditance = sqrtf(powf(plane->dest.x - plane->pos.x, 2) +
        powf(plane->dest.y - plane->pos.y, 2));
    plane->angle = -atan2f(array[2] - array[0], array[3] - array[1]);
    plane->speed.x = cosf(plane->angle) * array[4];
    plane->speed.y = sinf(plane->angle) * array[4];
    plane->norm_speed = array[4];
    plane->takeoff_time = array[5];
    plane->landing_time = plane->traveling_ditance / plane->norm_speed +
        plane->takeoff_time;
    plane->landed = plane->crashed = plane->flying = false;
    return EPITECH_SUCCESS;
}

static int get_nb_planes(char const *str, plane_t *plane)
{
    str += 2;
    float array[6];
    array[0] = lat_parse(str);
    str++;
    for (; *str != '-' && *str != '+'; str++);
    array[1] = long_parse(str);
    str = my_strstr(str, " ") + 1;
    array[2] = lat_parse(str);
    str++;
    for (; *str != '-' && *str != '+'; str++);
    array[3] = long_parse(str);
    str = my_strstr(str, " ");
    array[4] = (float) my_getnbr(str);
    str = my_strstr(str + 1, " ");
    array[5] = (float) my_getnbr(str);
    set_plane(array, plane);
}

static int geo_parse(char const *str, sfVector2f *dest)
{
    if (str == NULL || dest == NULL)
        return EPITECH_FAILURE;
    dest->x = lat_parse(str);
    int i;
    for (i = 1; str[i] != '-' && str[i] != '+'; i++);
    dest->y = long_parse(str);
    return 0;
}

static plane_array_t *plane_array_create(linked_list_t *list_plane)
{
    plane_array_t *plane_array = malloc(sizeof(plane_array_t));
    plane_array->size = list_plane->len;
    plane_array->planes = malloc(sizeof(plane_t) * list_plane->len);
    for (int i = 0; list_plane != NULL; i++) {
        plane_t *p = &plane_array->planes[i];
        get_nb_planes(list_plane->data, p);
        linked_list_t *tmp = list_plane->next;
        free(list_plane->data);
        free(list_plane);
        list_plane = tmp;
    }
    return plane_array;
}

static atc_array_t *atc_array_create(linked_list_t *list_atc)
{
    atc_array_t *atc_array = malloc(sizeof(atc_array_t));
    atc_array->size = list_atc->len;
    atc_array->atc = malloc(sizeof(atc_t) * list_atc->len);
    for (int i = 0; list_atc != NULL; i++) {
        atc_t *a = &atc_array->atc[i];
        char *str = list_atc->data + 1;
        int nb = my_getnbr(str);
        a->pos.x = (float) nb;
        str += my_nbrlen(nb, 10) + 1;
        nb = my_getnbr(str);
        a->pos.y = (float) nb;
        str += my_nbrlen(nb, 10) + 1;
        nb = my_getnbr(str);
        a->size.x = a->size.y = nb;
        linked_list_t *tmp = list_atc->next;
        free(list_atc->data);
        free(list_atc);
        list_atc = tmp;
    }
    return atc_array;
}

static int file_loop(FILE *file, instance_t *instance, linked_list_t
    *list[2], char *paths[3])
{
    size_t buffer_size = 16;
    char *buffer = malloc(sizeof(char) * buffer_size);
    while (getline(&buffer, &buffer_size, file) != -1) {
        if (buffer[0] == 'P')
            ltal(&list[0], my_strdup(buffer));
        if (buffer[0] == 'T')
            ltal(&list[1], my_strdup(buffer));
        if (buffer[0] == 'A' && paths[0] == NULL)
            paths[0] = my_strdup(buffer + 2);
        if (buffer[0] == 'H' && paths[2] == NULL)
            paths[2] = my_strdup(buffer + 2);
        if (buffer[0] == 'B' && paths[1] == NULL)
            paths[1] = my_strdup(buffer + 2);
    }
    for (int j = 0; j < 3; j++) {
        int i;
        for (i = 0; paths[j][i] != '\n'; i++);
        paths[j][i] = '\0';
    }
}

int open_file(char *path, instance_t *instance)
{
    FILE *config = fopen(path, "r");
    if (config == NULL)
        return EPITECH_FAILURE;
    linked_list_t *list[2] = {NULL, NULL};
    char *out[3] = {NULL, NULL, NULL};
    file_loop(config, instance, list, out);
    instance->i_plane = sfImage_createFromFile(out[0]);
    instance->i_map = sfImage_createFromFile(out[1]);
    instance->i_atc = sfImage_createFromFile(out[2]);
    instance->planes  = plane_array_create(list[0]);
    instance->atc = atc_array_create(list[1]);
    fclose(config);
    if (instance->planes == NULL || instance->atc == NULL)
        return EPITECH_FAILURE;
    return EPITECH_SUCCESS;
}
