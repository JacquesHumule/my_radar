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

static int file_loop(FILE *file, linked_list_t *list[2], char *p[4])
{
    size_t buffer_size = 16;
    char *buffer = malloc(sizeof(char) * buffer_size);
    while (getline(&buffer, &buffer_size, file) != -1) {
        if (buffer[0] == 'P') ltal(&list[0], my_strdup(buffer));
        if (buffer[0] == 'T') ltal(&list[1], my_strdup(buffer));
        if (buffer[0] == 'A' && p[0] == NULL) p[0] = my_strdup(buffer + 2);
        if (buffer[0] == 'H' && p[2] == NULL) p[2] = my_strdup(buffer + 2);
        if (buffer[0] == 'B' && p[1] == NULL) p[1] = my_strdup(buffer + 2);
        if (buffer[0] == 'F' && p[3] == NULL) p[3] = my_strdup(buffer + 2);
    }
    free(buffer);
    if (p[0] == NULL || p[1] == NULL || p[2] == NULL)
        return EPITECH_FAILURE;
    for (int j = 0; j < 4; j++) {
        int i;
        for (i = 0; p[j][i] != '\n'; i++);
        p[j][i] = '\0';
    }
    return EPITECH_SUCCESS;
}

int open_file(char *path, instance_t *instance)
{
    FILE *config = fopen(path, "r");
    if (config == NULL)
        return EPITECH_FAILURE;
    linked_list_t *list[2] = {NULL, NULL};
    char *out[4] = {NULL, NULL, NULL, NULL};
    file_loop(config, list, out);
    if (out[0] == NULL || out[1] == NULL || out[2] == NULL || list[0] == NULL
        || list[1] == NULL || out[3] == NULL)
        return EPITECH_FAILURE;
    instance->t_plane = sfTexture_createFromFile(out[0], NULL);
    instance->t_map = sfTexture_createFromFile(out[1], NULL);
    instance->t_atc = sfTexture_createFromFile(out[2], NULL);
    instance->a_planes = plane_array_create(list[0]);
    instance->a_atc = atc_array_create(list[1]);
    instance->font = sfFont_createFromFile(out[3]);
    fclose(config);
    free_opener(out, list);
    if (instance->a_planes == NULL || instance->a_atc == NULL)
        return EPITECH_FAILURE;
    return EPITECH_SUCCESS;
}
