/*
** EPITECH PROJECT, 2022
** task03
** File description:
** aifhafih
*/

#include <stdio.h>
#include "my.h"


char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    for (int i = 0; i < len / 2; i++) {
        char buf = str[i];
        str[i] = str[len - i];
        str[len - i] = buf;
    }
    return str;
}
