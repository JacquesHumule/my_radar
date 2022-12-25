/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main.c
*/

#include <stdio.h>
#include "my_radar.h"

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    return my_radar(av[1]);
}
