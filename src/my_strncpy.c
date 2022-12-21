/*
** EPITECH PROJECT, 2022
** task02
** File description:
** zefgvzfzhefb
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);
    int i = 0;
while (i < n) {
        if (i > len) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
        i++;
    }
    return dest;
}
