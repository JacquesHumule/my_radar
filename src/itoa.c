/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** itoa.c
*/

#include <stdint.h>
#include <stdlib.h>

static size_t nbr_size(intmax_t nbr, unsigned base)
{
    size_t size = 0;
    if (nbr == 0)
        return 1;
    uintmax_t nb = 0;
    if (nbr < 0) {
        nb = -nbr;
        size++;
    } else
        nb = nbr;
    while (nb != 0) {
        nb /= base;
        size++;
    }
    return size;
}

char *itoa(intmax_t nbr)
{
    size_t size = nbr_size(nbr, 10);
    char *str = malloc(sizeof(char) * size + 1);;
    str[size] = '\0';
    unsigned neg = 0;
    uintmax_t nb = 0;
    if (nbr < 0) {
        neg = 1;
        str[0] = '-';
        nb = -nbr;
    } else
        nb = nbr;
    while (size > neg) {
        str[--size] = (nb % 10) + '0';
        nb /= 10;
    }
    return str;
}
