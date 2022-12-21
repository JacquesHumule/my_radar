/*
** EPITECH PROJECT, 2022
** for various other files
** File description:
** Displays, one-by-one, the characters of a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
