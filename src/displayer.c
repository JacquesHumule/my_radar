/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** quadtree_bb.c
*/

#include "my_radar.h"
#include "my.h"

void init_states(instance_t *instance)
{
    instance->states.show_planes = true;
    instance->states.show_pbb = true;
    instance->states.show_atc = true;
    instance->states.show_atc_area = true;
    instance->states.show_quatree = false;
    instance->states.show_clock = true;
}

int display_bb(quadtree_t *head, instance_t *instance)
{
    if (head->display == NULL) {
        head->display = sfRectangleShape_create();
        sfRectangleShape_setPosition(head->display, (sfVector2f) {head->bb
        .left,
            head->bb.top});
        sfRectangleShape_setSize(head->display, (sfVector2f) {head->bb.width,
            head->bb.height});
        sfRectangleShape_setOutlineColor(head->display, sfYellow);
        sfRectangleShape_setFillColor(head->display, sfTransparent);
        sfRectangleShape_setOutlineThickness(head->display, 1);
    }
    sfRenderWindow_drawRectangleShape(instance->window, head->display, NULL);
    if (head->nb_planes <= 1 || head->bb.height < 20)
        return 0;
    for (int i = 0; i < 4; i++)
        display_bb(head->childs[i], instance);
    return 0;
}

void clock_displayer(instance_t *instance)
{
    if (instance->clock == NULL) {
        instance->clock = sfText_create();
        sfText_setFont(instance->clock, instance->font);
        sfText_setCharacterSize(instance->clock, 24);
        sfText_setColor(instance->clock, sfWhite);
        sfText_setStyle(instance->clock, sfTextRegular);
        sfText_setPosition(instance->clock, (sfVector2f) {1700, 10});
    }
    char *text = itoa(sfTime_asSeconds(sfClock_getElapsedTime
        (instance->clock_time)));
    sfText_setString(instance->clock, text);
    sfRenderWindow_drawText(instance->window, instance->clock, NULL);
    free(text);
}

int display_planes_bb(instance_t *instance)
{
    if (instance == NULL)
        return EPITECH_FAILURE;
    for (unsigned i = 0; i < instance->a_planes->last_stopped; i++) {
        plane_t *plane = &instance->a_planes->planes[i];
        float time = sfTime_asSeconds(sfClock_getElapsedTime(plane->clock));
        if (plane->takeoff_time <= time && plane->landing_time > time) {
            sfRenderWindow_drawRectangleShape(instance->window,
                plane->border, NULL);
        }
    }
    return EPITECH_SUCCESS;
}

void displayer(instance_t *instance)
{
    sfRenderWindow_drawSprite(instance->window, instance->s_map, NULL);
    if (instance->states.show_atc_area)
        atc_display_bb(instance);
    if (instance->states.show_atc)
        atc_display(instance);
    if (instance->states.show_quatree)
        display_bb(instance->quadtree ,instance);
    if (instance->states.show_pbb)
        display_planes_bb(instance);
    if (instance->states.show_planes)
        display_planes(instance);
    if (instance->states.show_clock)
        clock_displayer(instance);
}
