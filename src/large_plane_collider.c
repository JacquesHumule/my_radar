/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** large_plane_collider.c
*/

#include "my_radar.h"

void check_plane_collision(quadtree_t *head, instance_t *instance)
{
    for (int i = 0, j = 1; i < head->nb_planes; (j >= head->nb_planes - 1 ) ?
        i++, j = i + 1 : j++) {
        if (j >= head->nb_planes)
            return;
        if (sfFloatRect_intersects(&head->planes[i]->bb, &head->planes[j]->bb,
            NULL) && planes_in_atc_area(head->planes[i], instance) == false &&
            planes_in_atc_area(head->planes[j], instance) == false) {
            head->planes[i]->flying = head->planes[j]->flying = 0;
            head->planes[i]->crashed = head->planes[j]->crashed = 1;
        }
    }
}

int alloc_nodes(quadtree_t *head)
{
    for (int i = 0; i < 4; i++) {
        if (head->childs[i] == NULL)
            head->childs[i] = create_tree();
        if (head->childs[i] == NULL)
            return 84;
        if (head->childs[i]->planes != NULL)
            free(head->childs[i]->planes);
        head->childs[i]->planes = malloc(sizeof(plane_t *) * head->nb_planes);
        if (head->childs[i] == NULL)
            return 84;
        head->childs[i]->nb_planes = 0;
    }
    create_bounding_box(head);
    return 0;
}

int populate_nodes(quadtree_t *head, instance_t *instance)
{
    if (head->bb.width < 20) {
        check_plane_collision(head, instance);
        return 0;
    }
    if (head->nb_planes <= 1)
        return 0;
    if (alloc_nodes(head) == 84)
        return 84;
    for (int i = 0, j = 0; i < head->nb_planes; (j == 3) ? j = 0, i++ : j++) {
        sfFloatRect bb = head->planes[i]->bb;
        if (sfFloatRect_intersects(&head->childs[j]->bb, &bb, NULL))
            head->childs[j]->planes[head->childs[j]->nb_planes++] =
                head->planes[i];
    }
    for (int i = 0; i < 4; i++)
        populate_nodes(head->childs[i], instance);
    return 0;
}

int check_collision(instance_t *instance)
{
    quadtree_t *head = instance->quadtree;
    if (head->planes != NULL)
        free(head->planes);
    head->planes = malloc(sizeof(plane_t*) * instance->a_planes->last_stopped);
    if (head->planes == NULL)
        return EPITECH_FAILLURE;
    head->nb_planes = 0;
    for (int i = 0; i < instance->a_planes->last_stopped; i++)
        if (instance->a_planes->planes[i].flying == true)
            head->planes[head->nb_planes++] = &instance->a_planes->planes[i];
    sfVector2u usize = sfRenderWindow_getSize(instance->window);
    sfVector2i isize = {.x = (int) usize.x, .y = (int) usize.y};
    sfVector2f start = sfRenderWindow_mapPixelToCoords(instance->window,
        (sfVector2i) {0, 0}, NULL);
    sfVector2f end = sfRenderWindow_mapPixelToCoords(instance->window, isize,
        NULL);
    head->bb = (sfFloatRect) {start.x, start.y, end.x, end.y};
    populate_nodes(head, instance);
    return 0;
}
