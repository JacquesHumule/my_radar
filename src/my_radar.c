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
    if (map == NULL || instance == NULL || instance->t_map == NULL)
        return EPITECH_FAILURE;
    if (instance->t_map == NULL)
        return EPITECH_FAILURE;
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
        return EPITECH_FAILURE;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, (sfVector2i) {0, 0});
    instance->window = window;
    instance->quadtree = create_tree();
    instance->clock = NULL;
    instance->clock_time = sfClock_create();
    init_states(instance);
    if (create_backgound(instance) == EPITECH_FAILURE
        || create_planes(instance) == EPITECH_FAILURE
        || atc_create(instance) == EPITECH_FAILURE
        || instance->quadtree == NULL)
        return EPITECH_FAILURE;
    return EPITECH_SUCCESS;
}

int event_manager(instance_t *instance)
{
    sfRenderWindow *window = instance->window;
    if (window == NULL) return EPITECH_FAILURE;
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyQ))) sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyA))
            instance->states.show_planes = !instance->states.show_planes;
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyZ))
            instance->states.show_pbb = !instance->states.show_pbb;
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyE))
            instance->states.show_atc = !instance->states.show_atc;
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyR))
            instance->states.show_atc_area = !instance->states.show_atc_area;
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyT))
            instance->states.show_quatree = !instance->states.show_quatree;
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyY))
            instance->states.show_clock = !instance->states.show_clock;
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
    if (instance->t_plane != NULL)
        sfTexture_destroy(instance->t_plane);
    if (instance->t_atc != NULL)sfTexture_destroy(instance->t_atc);
    sfTexture_destroy(instance->t_map);
    sfSprite_destroy(instance->s_map);
    sfText_destroy(instance->clock);
    sfClock_destroy(instance->clock_time);
    sfFont_destroy(instance->font);
    free_quadtree(instance->quadtree);
    free(instance);
}

int my_radar(char *path)
{
    instance_t *instance = malloc(sizeof(instance_t));
    if (open_file(path, instance) == EPITECH_FAILURE
        || init(instance) == EPITECH_FAILURE)
        return EPITECH_FAILURE;
    sfRenderWindow *window = instance->window;
    while (sfRenderWindow_isOpen(instance->window)
        && instance->a_planes->last_stopped) {
        event_manager(instance);
        update_planes(instance);
        check_collision(instance);
        sfRenderWindow_clear(window, sfBlack);
        displayer(instance);
        sfRenderWindow_display(window);
    }
    free_radar(instance);
    return EPITECH_SUCCESS;
}
