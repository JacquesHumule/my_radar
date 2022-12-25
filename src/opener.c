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
    for (int j = 0; j < 3; j++) {
        int i;
        for (i = 0; paths[j][i] != '\n'; i++);
        paths[j][i] = '\0';
    }
}

int open_file(char *path, instance_t *instance)
{
    FILE *config = fopen(path, "r");
    if (config == NULL)
        return EPITECH_FAILURE;
    linked_list_t *list[2] = {NULL, NULL};
    char *out[3] = {NULL, NULL, NULL};
    file_loop(config, instance, list, out);
    instance->i_plane = sfImage_createFromFile(out[0]);
    instance->i_map = sfImage_createFromFile(out[1]);
    instance->i_atc = sfImage_createFromFile(out[2]);
    instance->planes = plane_array_create(list[0]);
    instance->atc = atc_array_create(list[1]);
    fclose(config);
    if (instance->planes == NULL || instance->atc == NULL)
        return EPITECH_FAILURE;
    return EPITECH_SUCCESS;
}
