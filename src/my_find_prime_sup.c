/*
** EPITECH PROJECT, 2022
** task07
** File description:
** find the next prime number
*/

#include "my.h"

int my_find_prime_sup(int n)
{
    unsigned int out = n;
    while (my_is_prime(out) == 0) {
        out++;
        if (out > 2147483647)
            return n;
    }
    return out;
}
