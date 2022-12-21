/*
** EPITECH PROJECT, 2022
** task04
** File description:
** function that displays either N if the integer passed as
** parameter is negative or P, if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
    int out = 80;
    if (n < 0) {
        out = 78;
    }
    my_putchar(out);
    return 0;
}
