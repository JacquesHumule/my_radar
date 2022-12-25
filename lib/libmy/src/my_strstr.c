/*
** EPITECH PROJECT, 2022
** task05
** File description:
** hbfhezfbezkfbez
*/

#include <stddef.h>
#include "my.h"

static int my_checkocc(char *hs, char const *nd, int i)
{
    for (int p = 0; hs[i + p] == nd[p] || nd[p] == '\0';
            p++) {
                if (nd[p] == '\0') {
                    return 1;
                }
    }
    return 0;
}

char const *my_strstr(char const *haystack, char const *needle)
{
    int len = my_strlen(haystack);
    int lan = my_strlen(needle);
    if (lan == 0)
        return haystack;
    for (int i = 0; i <= len - lan; i++) {
        if (my_checkocc(haystack, needle, i) == 1)
            return &haystack[i];
    }
    return NULL;
}
