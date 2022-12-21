/*
** EPITECH PROJECT, 2022
** task04
** File description:
** powering numbers recursive
*/

long double my_compute_power_rec(long double nb, int p)
{
    if (p == 0)
        return 1l;
    if (p < 0)
        return my_compute_power_rec(nb, p + 1) / nb;
    return my_compute_power_rec(nb, p - 1) * nb;
}
