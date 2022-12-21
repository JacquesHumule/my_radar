/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** opener.c
*/

#include <malloc.h>
#include <stdio.h>

int open_file(char *path)
{
    size_t buffer_size = 4096;
    char *buffer = malloc(sizeof(char) * buffer_size);
    FILE *config = fopen(path, "r");
    if (config == NULL) {
        return 84;
    }
    while (getline(&buffer, &buffer_size, config) != -1) {
        printf("%s", buffer);
    }
    return 0;
}
