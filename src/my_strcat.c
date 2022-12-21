/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** zaqfzefzegfz
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int len = my_strlen(dest);
    int i;
    for (i = 0 ; src[i] != '\0' ; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
