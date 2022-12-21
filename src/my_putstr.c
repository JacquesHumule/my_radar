/*
** EPITECH PROJECT, 2022
** for %s
** File description:
** Displays, one-by-one, characters of the string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
