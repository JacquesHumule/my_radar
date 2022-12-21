/*
** EPITECH PROJECT, 2022
** task05
** File description:
** function that returns a number, sent to the function as a string
*/

static int in_limits(long long nbr)
{
    if (nbr < -2147483648 || nbr > 2147483647)
        return 0;
    return nbr;
}

int my_getnbr(char const *str)
{
    int let_acc = 1;
    long long nbr = 0;
    int neg = 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '-' && let_acc == 1)
            neg *= -1;
        if (str[i] == '-' && let_acc == 0)
            return in_limits(neg * nbr);
        if ('0' <= str[i] && str[i] <= '9') {
            let_acc = 0;
            nbr = nbr * 10 + (str[i] - '0');
            }
        if ((str[i] < '0' || str [i] > '9') && let_acc == 0)
            return in_limits(neg * nbr);
    }
    return in_limits(neg * nbr);
}
