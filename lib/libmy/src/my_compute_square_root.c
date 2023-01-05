/*
** EPITECH PROJECT, 2022
** task05
** File description:
** return √
*/
#include <stdio.h>

int my_compute_square_root(int n)
{
    if (n < 0)
        return 0;
    for (int i = 1; i * i <= n; i++) {
        int j = i * i;
        if (j > 2147483647)
            return 0;
        if (j == n)
            return i;
    }
    return 0;
}
