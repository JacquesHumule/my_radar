/*
** EPITECH PROJECT, 2022
** task01
** File description:
** ufzheu
*/

#include <malloc.h>

size_t my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    size_t len = my_strlen(src);
    char *out = malloc(sizeof(char) * (len + 1));
    for (unsigned i = 0; i < len; i++) {
        out[i] = src[i];
    }
    return out;
}
