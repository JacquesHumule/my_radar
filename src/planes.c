/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** planes.c
*/

#include <math.h>
#include "my_radar.h"
#include "objects.h"

static int create_rect(plane_t *plane)
{
    if (plane == NULL)
        return EPITECH_FAILURE;
    sfVector2f size = {20, 20};
    sfVector2f origin = {10, 10};
    plane->border = sfRectangleShape_create();
    if (plane->border == NULL)
        return EPITECH_FAILURE;
    sfRectangleShape_setOrigin(plane->border, origin);
    sfRectangleShape_setSize(plane->border, size);
    sfRectangleShape_setFillColor(plane->border, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->border, sfRed);
    sfRectangleShape_setOutlineThickness(plane->border, 1);
    sfRectangleShape_setRotation(plane->border, plane->angle * 180 / M_PI);
    return EPITECH_SUCCESS;
}

int create_planes(instance_t *instance)
{
    if (instance == NULL)
        return EPITECH_FAILURE;
    for (unsigned i = 0; i < instance->a_planes->size; i++) {
        plane_t *plane = &instance->a_planes->planes[i];
        plane->sprite = sfSprite_create();
        plane->clock = sfClock_create();
        if (plane->sprite == NULL || plane->clock == NULL)
            return EPITECH_FAILURE;
        sfVector2u size = sfTexture_getSize(instance->t_plane);
        sfVector2f origin = {(float) size.x / 2,(float) size.y / 2};
        sfSprite_setOrigin(plane->sprite, origin);
        sfSprite_setTexture(plane->sprite, instance->t_plane, sfTrue);
        sfVector2f scale = {20.f / (float) size.x, 20.f / (float) size.y};
        sfSprite_setScale(plane->sprite, scale);
        sfSprite_setRotation(plane->sprite, plane->angle / (float) M_PI * 180);
        if (create_rect(plane) == EPITECH_FAILURE)
            return EPITECH_FAILURE;
        plane->flying = plane->landed = plane->crashed = 0;
    }
    return EPITECH_SUCCESS;
}

int display_planes(instance_t *instance)
{
    if (instance == NULL)
        return EPITECH_FAILURE;
    for (unsigned i = 0; i < instance->a_planes->last_stopped; i++) {
        plane_t *plane = &instance->a_planes->planes[i];
        float time = sfTime_asSeconds(sfClock_getElapsedTime(plane->clock));
        if (plane->takeoff_time <= time && plane->landing_time > time) {
            sfRenderWindow_drawSprite(instance->window, plane->sprite, NULL);
        }
    }
    return EPITECH_SUCCESS;
}

int is_flying(plane_t *plane)
{
    if (plane == NULL)
        return EPITECH_FAILURE;
    if (plane->crashed == true || plane->landed == true)
        return false;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(plane->clock));
    if (plane->landing_time < time) {
        plane->landed = true;
        return false;
    }
    if (plane->takeoff_time <= time || plane->flying == false)
        plane->flying = true;
    return true;
}

int update_planes(instance_t *instance)
{
    if (instance == NULL) return EPITECH_FAILURE;
    sfVector2u s = sfTexture_getSize(instance->t_map);
    for (unsigned i = 0; i < instance->a_planes->last_stopped; i++) {
        plane_t *p = &instance->a_planes->planes[i];
        if (is_flying(p) == false) {
            swap_planes(instance, i);
            continue;
        }
        float time = sfTime_asSeconds(sfClock_getElapsedTime(p->clock)) -
            p->takeoff_time;
        if (p->flying == true) {
            float pos_y = (-p->origin.y + p->speed.y * time + 90) * s.y / 180;
            float pos_x = (p->origin.x + p->speed.x * time + 180) * s.x / 360;
            p->pos = (sfVector2f) {pos_x, pos_y};
            sfSprite_setPosition(p->sprite, p->pos);
            sfRectangleShape_setPosition(p->border, p->pos);
            p->bb = (sfFloatRect) {pos_x - 10, pos_y - 10, 20, 20};
        }
    }
    return EPITECH_SUCCESS;
}
