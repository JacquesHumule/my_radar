/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** quadtree_bb.c
*/

#include "objects.h"

int display_bb(quadtree_t *head, instance_t *instance)
{
    if (head->display == NULL) {
        head->display = sfRectangleShape_create();
        sfRectangleShape_setPosition(head->display, (sfVector2f) {head->bb
        .left,
            head->bb.top});
        sfRectangleShape_setSize(head->display, (sfVector2f) {head->bb.width,
            head->bb.height});
        sfRectangleShape_setOutlineColor(head->display, sfBlack);
        sfRectangleShape_setFillColor(head->display, sfTransparent);
        sfRectangleShape_setOutlineThickness(head->display, 1);
    }
    sfRenderWindow_drawRectangleShape(instance->window, head->display, NULL);
    if (head->nb_planes <= 1 || head->bb.width < 20)
        return 0;
    for (int i = 0; i < 4; i++)
        display_bb(head->childs[i], instance);
    return 0;
}
