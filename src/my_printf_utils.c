/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-jacques.rathier
** File description:
** my_printf_utils
*/

#include "my_printf.h"

int my_char_isnum(char const c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int count_nbr(uintmax_t nbr, int base, int is_alt, my_printf_conv_t conv)
{
    int sum = 0;
    if (nbr == 0)
        return 0;
    while (nbr != 0) {
        nbr /= base;
        sum++;
    }
    if (is_alt && base == 16 && (conv == CONV_X || conv == CONV_x))
        return sum + 2;
    if (is_alt && base == 8 && conv == CONV_o)
        return sum + 1;
    if (is_alt && (conv == CONV_F || conv == CONV_f))
        return sum + 1;
    return sum;
}

void my_printf_setint(my_printf_arg_t *parse,intmax_t nbr, int is_signed)
{
    parse->data.neg = 0;
    parse->data.is_signed = 0;
    if (is_signed) {
        if (nbr < 0) {
            nbr *= -1;
            parse->data.neg = 1;
        }
        parse->data.is_signed = 1;
        parse->data.value.integer = nbr;
    } else {
        parse->data.value.integer = nbr;
    }
}

void my_printf_setflt(my_printf_arg_t *parse,long double nbr)
{
    union {
        double nb;
        struct salut {
            unsigned long long pad : 52;
            unsigned long long pad2 : 11;
            unsigned int sign : 1;
        } decomp;
    } sign;
    sign.nb = (double) nbr;
    parse->data.is_signed = 1;
    parse->data.neg = 0;
    if (nbr < 0 || (sign.decomp.sign && nbr == 0)) {
        nbr *= -1;
        parse->data.neg = 1;
        parse->data.value.floating = nbr;
    } else {
        parse->data.value.floating = nbr;
    }
}

int float_exp(long double nb, int base)
{
    int exp = 0;
    if (nb == 0)
        return 0;
    while (nb > base) {
        nb /= base;
        exp++;
    }
    while (nb < 1) {
        nb *= base;
        exp--;
    }
    return exp;
}
