/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** large_plane_collider_utils.c
*/

#include "my_radar.h"

int create_bounding_box(quadtree_t *head)
{
    head->childs[TL]->bb.top = head->childs[TR]->bb.top = head->bb.top;
    head->childs[BL]->bb.top = head->childs[BR]->bb.top = head->bb.top +
        head->bb.height / 2;
    head->childs[TL]->bb.left = head->childs[BL]->bb.left = head->bb.left;
    head->childs[TR]->bb.left = head->childs[BR]->bb.left = head->bb.left +
        head->bb.width / 2;
    head->childs[TL]->bb.width = head->childs[TR]->bb.width =
        head->childs[BL]->bb.width = head->childs[BR]->bb.width = head->bb
            .width / 2;
    head->childs[TL]->bb.height = head->childs[TR]->bb.height =
        head->childs[BL]->bb.height = head->childs[BR]->bb.height = head->bb
            .height / 2;
    return 0;
}

quadtree_t *create_tree(void)
{
    quadtree_t *out = malloc(sizeof(quadtree_t));
    if (out == NULL)
        return NULL;
    for (int i = 0; i < 4; i++)
        out->childs[i] = NULL;
    out->nb_planes = 0;
    out->planes = NULL;
    out->display = NULL;
    return out;
}

void free_quadtree(quadtree_t *quadtree)
{
    if (quadtree == NULL)
        return;
    if (quadtree->planes != NULL)
        free(quadtree->planes);
    if (quadtree->display != NULL)
        sfRectangleShape_destroy(quadtree->display);
    for (int i = 0; i < 4; i++)
        free_quadtree(quadtree->childs[i]);
    free(quadtree);
}
