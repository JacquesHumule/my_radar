/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** opener.c
*/

#include <stdio.h>
#include "my.h"
#include "linked_list.h"
#include "objects.h"
#include "my_radar.h"

static void free_opener(char *path[3], linked_list_t *list[2])
{
    if (path != NULL) {
        if (path[0] != NULL)
            free(path[0]);
        if (path[1] != NULL)
            free(path[1]);
        if (path[2] != NULL)
            free(path[2]);
    }
    if (list != NULL) {
        if (list[0] != NULL)
            ltfree(list[0], free);
        if (list[1] != NULL)
            ltfree(list[1], free);
    }
}

static int file_loop(FILE *file, instance_t *instance, linked_list_t
    *list[2], char *paths[3])
{
    size_t buffer_size = 16;
    char *buffer = malloc(sizeof(char) * buffer_size);
    while (getline(&buffer, &buffer_size, file) != -1) {
        if (buffer[0] == 'P')
            ltal(&list[0], my_strdup(buffer));
        if (buffer[0] == 'T')
            ltal(&list[1], my_strdup(buffer));
        if (buffer[0] == 'A' && paths[0] == NULL)
            paths[0] = my_strdup(buffer + 2);
        if (buffer[0] == 'H' && paths[2] == NULL)
            paths[2] = my_strdup(buffer + 2);
        if (buffer[0] == 'B' && paths[1] == NULL)
            paths[1] = my_strdup(buffer + 2);
    }
    free(buffer);
    if (paths[0] == NULL || paths[1] == NULL || paths[2] == NULL)
        return EPITECH_FAILLURE;
    for (int j = 0; j < 3; j++) {
        int i;
        for (i = 0; paths[j][i] != '\n'; i++);
        paths[j][i] = '\0';
    }
    return EPITECH_SUCCESS;
}

int open_file(char *path, instance_t *instance)
{
    FILE *config = fopen(path, "r");
    if (config == NULL)
        return EPITECH_FAILURE;
    linked_list_t *list[2] = {NULL, NULL};
    char *out[3] = {NULL, NULL, NULL};
    file_loop(config, instance, list, out);
    if (out[0] == NULL || out[1] == NULL || out[2] == NULL || list[0] == NULL
        || list[1] == NULL)
        return EPITECH_FAILLURE;
    instance->i_plane = sfImage_createFromFile(out[0]);
    instance->i_map = sfImage_createFromFile(out[1]);
    instance->i_atc = sfImage_createFromFile(out[2]);
    instance->a_planes = plane_array_create(list[0]);
    instance->a_atc = atc_array_create(list[1]);
    fclose(config);
    free_opener(out, list);
    if (instance->a_planes == NULL || instance->a_atc == NULL)
        return EPITECH_FAILURE;
    return EPITECH_SUCCESS;
}
