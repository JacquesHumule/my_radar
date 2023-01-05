/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main.c
*/

#include <stdio.h>
#include "my.h"
#include "my_radar.h"

void help(void)
{
    my_printf(
        "USAGE:\n"
        "\t./my_radar file\n"
        "\n\tShortcuts:\n"
        "\t A toggle plane visibility\n"
        "\t Z toggle plane box visibility\n"
        "\t E toggle atc visibility\n"
        "\t R toggle atc circle visibility\n"
        "\t T toggle quadtree visibility\n"
        "\t Y toggle clock visibility\n"
        "\nDESCRIPTION:\n"
        "\tfile\tfile describing the atc, planes and settings\n");
}

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        help();
        return 0;
    }
    return my_radar(av[1]);
}
