/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main.c
*/

#include <stdio.h>
#include "my.h"
#include "my_radar.h"

int check_display(char const * const *env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (!my_strncmp(env[i], "DISPLAY=", 8))
            return 0;
    return 1;
}

void help(void)
{
    my_printf(
        "USAGE:\n"
        "\t./my_radar file\n"
        "\n\tShortcuts:\n"
        "\t S toggle plane and atc visibility\n"
        "\t L toggle atc circle and plane box visibility\n"
        "\t T toggle quadtree visibility\n"
        "\t Y toggle clock visibility\n"
        "\t Q to quit\n"
        "\nDESCRIPTION:\n"
        "\tfile\tfile describing the atc, planes and settings\n");
}

int main (int ac, char **av, char const * const * env)
{
    if (check_display(env)) return 84;
    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        help();
        return 0;
    }
    return my_radar(av[1]);
}
