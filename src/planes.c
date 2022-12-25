/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** planes.c
*/

#include <math.h>
#include "my_radar.h"
#include "objects.h"

int create_rect(plane_t *plane)
{
    sfVector2f size = {20, 20};
    sfVector2f origin = {10, 10};
    plane->hitbox = sfRectangleShape_create();
    sfRectangleShape_setOrigin(plane->hitbox, origin);
    sfRectangleShape_setSize(plane->hitbox, size);
    sfRectangleShape_setFillColor(plane->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 1);
    sfRectangleShape_setRotation(plane->hitbox, plane->angle * 180 / M_PI);
    return 0;
}

int create_planes(instance_t *instance)
{
    for (int i = 0; i < instance->planes->size; i++) {
        plane_t *plane = &instance->planes->planes[i];
        plane->sprite = sfSprite_create();
        plane->texture = sfTexture_createFromImage(instance->i_plane, NULL);
        sfTexture_setSmooth(plane->texture, sfTrue);
        sfVector2u size = sfTexture_getSize(plane->texture);
        sfVector2f origin = {size.x / 2, size.y / 2};
        sfSprite_setOrigin(plane->sprite, origin);
        sfSprite_setTexture(plane->sprite, plane->texture, sfTrue);
        sfVector2f scale = {20.f / size.x, 20.f / size.y};
        sfSprite_setScale(plane->sprite, scale);
        plane->clock = sfClock_create();
        sfSprite_setRotation(plane->sprite, plane->angle / (float) M_PI * 180);
        plane->hitbox = sfRectangleShape_create();
        create_rect(plane);
    }
    return 0;
}

int display_planes(instance_t *instance)
{
    for (int i = 0; i < instance->planes->last_stopped; i++) {
        plane_t *plane = &instance->planes->planes[i];
        float time = sfTime_asSeconds(sfClock_getElapsedTime(plane->clock));
        if (plane->takeoff_time <= time && plane->landing_time > time) {
            sfRenderWindow_drawRectangleShape(instance->window,
                plane->hitbox, NULL);
            sfRenderWindow_drawSprite(instance->window, plane->sprite, NULL);
        }
    }
    return 0;
}

int is_flying(plane_t *plane)
{
    if (plane->crashed || plane->landed)
        return 0;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(plane->clock));
    if (plane->landing_time < time) {
        plane->landed = true;
        return 1;
    }
    if (plane->takeoff_time <= time || !plane->flying)
        plane->flying = true;
    return 0;
}

int update_planes(instance_t *instance)
{
    sfVector2u size = sfImage_getSize(instance->i_map);
    for (int i = 0; i < instance->planes->last_stopped; i++) {
        plane_t *plane = &instance->planes->planes[i];
        if (is_flying(plane)) {
            size_t j = instance->planes->last_stopped - 1;
            plane_t tmp = instance->planes->planes[j];
            instance->planes->planes[j] = *plane;
            instance->planes->planes[i] = tmp;
            instance->planes->last_stopped--;
        }
        float time = sfTime_asSeconds(sfClock_getElapsedTime(plane->clock)) -
            plane->takeoff_time;
        if (plane->flying) {
            float posy = (-plane->origin.y + plane->speed.y * time + 90)
                * size.y / 180;
            float posx = (plane->origin.x + plane->speed.x * time + 180)
                * size.x / 360;
            plane->pos = (sfVector2f) {posx, posy};
            sfSprite_setPosition(plane->sprite, plane->pos);
            sfRectangleShape_setPosition(plane->hitbox, plane->pos);
        }
    }
    return 0;
}
