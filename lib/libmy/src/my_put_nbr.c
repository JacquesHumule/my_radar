/*
** EPITECH PROJECT, 2022
** task07
** File description:
** function that displays the number given as a parameter
*/

#include <stdint.h>
#include <glob.h>
#include "my.h"

static int my_put_nbr_r(int nbr)
{
    long n = nbr;
    if (n < 0) {
        my_putchar('-');
        n = n * -1;
    }
    if (n == 0)
        return 0;
    my_put_nbr_r(n / 10);
    my_putchar(n % 10 + 48);
    return 0;
}

int my_put_nbr(int nbr)
{
    if (nbr == 0) {
        my_putchar('0');
        return 0;
    }
    my_put_nbr_r(nbr);
    return 0;
}

size_t my_nbrlen(intmax_t nbr, int base)
{
    int len = 0;
    if (nbr < 0) {
        len++;
        nbr = nbr * -1;
    }
    while (nbr > 0) {
        nbr = nbr / base;
        len++;
    }
    return len;
}
