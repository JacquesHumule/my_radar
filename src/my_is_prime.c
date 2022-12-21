/*
** EPITECH PROJECT, 2022
** task06
** File description:
** return 1 if number is prime, 0 else
*/

static int le_vrai_sqrt_approximatif(int nb)
{
    int out = 1;
    for (int i = 1; i * i <= nb; i++) {
        out = i;
        unsigned int j = i * i;
        if (i * i == nb)
            return out;
        if (j > 2147483647)
            return 46341;
    }
    return out;
}

int my_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    int sqrn = le_vrai_sqrt_approximatif(nb) + 1;
    for (int i = 2; i < sqrn; i++) {
        if (nb / i * i == nb)
            return 0;
    }
    return 1;
}
