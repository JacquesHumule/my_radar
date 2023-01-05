/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** planes_utils.c
*/

#include "my_radar.h"

int swap_planes(instance_t *instance, size_t i)
{
    if (instance == NULL || i >= instance->a_planes->last_stopped)
        return EPITECH_FAILURE;
    size_t j = instance->a_planes->last_stopped - 1;
    plane_t tmp = instance->a_planes->planes[j];
    instance->a_planes->planes[j] = instance->a_planes->planes[i];
    instance->a_planes->planes[i] = tmp;
    instance->a_planes->last_stopped--;
    return EPITECH_SUCCESS;
}

static void free_plane(plane_t *plane)
{
    if (plane == NULL)
        return;
    if (plane->sprite != NULL)
        sfSprite_destroy(plane->sprite);
    if (plane->clock != NULL)
        sfClock_destroy(plane->clock);
    if (plane->border != NULL)
        sfRectangleShape_destroy(plane->border);
}

void free_plane_array(plane_array_t *array)
{
    if (array == NULL)
        return;
    if (array->planes != NULL) {
        for (unsigned i = 0; i < array->size; i++)
            free_plane(&array->planes[i]);
        free(array->planes);
    }
    free(array);
}

static void free_atc(atc_t *atc)
{
    if (atc == NULL)
        return;
    if (atc->sprite != NULL)
        sfSprite_destroy(atc->sprite);
    if (atc->border != NULL)
        sfCircleShape_destroy(atc->border);
}

void free_atc_array(atc_array_t *array)
{
    if (array == NULL)
        return;
    if (array->atc != NULL) {
        for (int i = 0; i < array->size; i++)
            free_atc(&array->atc[i]);
        free(array->atc);
    }
    free(array);
}
