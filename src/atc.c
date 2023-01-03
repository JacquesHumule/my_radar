/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** atc.c
*/

#include "objects.h"

static int circle_create(atc_t *atc, instance_t *instance)
{
    sfVector2u s = sfImage_getSize(instance->i_map);
    atc->radius = atc->radius * s.x / 360;
    atc->border = sfCircleShape_create();
    sfCircleShape_setPosition(atc->border, atc->pos);
    sfCircleShape_setRadius(atc->border, atc->radius);
    sfCircleShape_setFillColor(atc->border, (sfColor) {0xF0, 0xFF, 0xFF,
        0x30});
    sfCircleShape_setOutlineColor(atc->border, sfCyan);
    sfCircleShape_setOutlineThickness(atc->border, 2);
    sfVector2f origin = {atc->radius, atc->radius};
    sfCircleShape_setOrigin(atc->border, origin);
    return 0;
}

int atc_create(instance_t *instance)
{
    sfVector2u s = sfImage_getSize(instance->i_map);
    for (int i = 0; i < instance->a_atc->size; i++) {
        atc_t *atc = &instance->a_atc->atc[i];
        atc->sprite = sfSprite_create();
        atc->texture = sfTexture_createFromImage(instance->i_atc, NULL);
        sfTexture_setSmooth(atc->texture, sfTrue);
        sfSprite_setTexture(atc->sprite, atc->texture, sfFalse);
        sfVector2u size = sfTexture_getSize(atc->texture);
        sfVector2f origin = {(float) size.x / 2, (float) size.x / 2};
        sfSprite_setOrigin(atc->sprite, origin);
        sfVector2f scale = {20.f / (float) size.x, 20.f / (float) size.y};
        sfSprite_setScale(atc->sprite, scale);
        float posy = (-atc->pos.y + 90) * s.y / 180;
        float posx = (atc->pos.x + 180) * s.x / 360;
        atc->pos = (sfVector2f) {posx, posy};
        sfSprite_setPosition(atc->sprite, atc->pos);
        circle_create(atc, instance);
    }
    return 0;
}

int atc_display(instance_t *instance)
{
    for (int i = 0; i < instance->a_atc->size; i++) {
        atc_t atc = instance->a_atc->atc[i];
        sfRenderWindow_drawCircleShape(instance->window, atc.border, NULL);
        sfRenderWindow_drawSprite(instance->window, atc.sprite, NULL);
    }
    return 0;
}

bool planes_in_atc_area(plane_t *plane, instance_t *instance)
{
    for (int i = 0; i < instance->a_atc->size; i++) {
        atc_t atc = instance->a_atc->atc[i];
        float d = (plane->pos.x - atc.pos.x) * (plane->pos.x - atc.pos.x)
            + (plane->pos.y - atc.pos.y) * (plane->pos.y - atc.pos.y);
        if (d < atc.radius * atc.radius)
            return true;
    }
    return false;
}
