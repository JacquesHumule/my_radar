/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar.c
*/

#include "objects.h"
#include "my_radar.h"

int create_backgound(instance_t *instance)
{
    sfSprite *map = sfSprite_create();
    if (map == NULL || instance == NULL || instance->i_map == NULL)
        return EPITECH_FAILLURE;
    instance->t_map = sfTexture_createFromImage(instance->i_map, NULL);
    if (instance->t_map == NULL)
        return EPITECH_FAILLURE;
    sfSprite_setTexture(map, instance->t_map, sfFalse);
    instance->s_map = map;
    return EPITECH_SUCCESS;
}

int init(instance_t *instance)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfContextSettings settings = {0, 0, 8, 0, 0, 0, 0};
    sfRenderWindow *window = sfRenderWindow_createUnicode(mode,
        (sfUint32 *) L"my_radar ∞", sfClose, &settings);
    if (window == NULL)
        return EPITECH_FAILLURE;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, (sfVector2i) {0, 0});
    instance->window = window;
    instance->quadtree = create_tree();
    if (create_backgound(instance) == EPITECH_FAILLURE
        || create_planes(instance) == EPITECH_FAILLURE
        || atc_create(instance) == EPITECH_FAILLURE
        || instance->quadtree == NULL)
        return EPITECH_FAILLURE;
    return EPITECH_SUCCESS;
}

int event_manager(sfRenderWindow *window)
{
    if (window == NULL)
        return EPITECH_FAILLURE;
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    return EPITECH_SUCCESS;
}

void free_radar(instance_t *instance)
{
    if (instance == NULL)
        return;
    if (instance->window != NULL)
        sfRenderWindow_destroy(instance->window);
    if (instance->a_planes != NULL)
        free_plane_array(instance->a_planes);
    if (instance->a_atc != NULL)
        free_atc_array(instance->a_atc);
    if (instance->i_plane != NULL)
        sfImage_destroy(instance->i_plane);
    if (instance->i_atc != NULL)
        sfImage_destroy(instance->i_atc);
    if (instance->i_map != NULL)
        sfImage_destroy(instance->i_map);
    if (instance->t_map != NULL)
        sfTexture_destroy(instance->t_map);
    if (instance->s_map != NULL)
        sfSprite_destroy(instance->s_map);
    if (instance->quadtree != NULL)
        free_quadtree(instance->quadtree);
    free(instance);
}

int my_radar(char *path)
{
    instance_t *instance = malloc(sizeof(instance_t));
    if (open_file(path, instance) == EPITECH_FAILLURE || init(instance) == EPITECH_FAILLURE)
        return EPITECH_FAILLURE;
    sfRenderWindow *window = instance->window;
    while (sfRenderWindow_isOpen(instance->window)
        && instance->a_planes->last_stopped) {
        event_manager(instance->window);
        update_planes(instance);
        check_collision(instance);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, instance->s_map, NULL);
        atc_display(instance);
        display_planes(instance);
        sfRenderWindow_display(window);
    }
    free_radar(instance);
    return EPITECH_SUCCESS;
}
