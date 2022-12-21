/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_dlb_suite.c
*/

#include "my_printf.h"
#include "my.h"

void my_printf_dbl_g(my_printf_arg_t *parse, va_list ap)
{
    va_list bp;
    va_copy(bp, ap);
    my_printf_dbl_getargs(parse, ap);
    unsigned int is_maj = parse->conv - CONV_g;
    int exp = float_exp(parse->data.value.floating, 10);
    int precis = (parse->precision < 0) ? 6 : parse->precision;
    long double nb = parse->data.value.floating;
    int last = 0;
    nb += 5l * my_compute_power_rec(10, -precis - 1);
    for (int i = 1; i <= precis || i == 0; i++)
        if ((uintmax_t) (nb *= 10) % 10 != 0)
            last = i;
    if (exp < -4 || exp >= precis) {
        parse->precision = -1;
        parse->conv = CONV_e + is_maj;
    } else {
        parse->precision = last;
        parse->conv = CONV_f + is_maj;
    }
    conversion_fx[parse->conv](parse, bp);
}

void my_printf_dbl_a(my_printf_arg_t *parse, va_list ap)
{
    parse->data.base = 16;
    int is_maj = parse->conv - CONV_a;
    my_printf_dbl_getargs(parse, ap);
    int exp = float_exp(parse->data.value.floating, 10);
    int precis = (parse->precision < 0) ? 6 : parse->precision;
    parse->data.value.floating += 5l
        * my_compute_power_rec(10l, exp - precis - 1);
    my_printf_dbl_a_getpad(parse);
    my_printf_nbr_spad(parse);
    my_printf_nbr_zpad(parse);
    my_printf_dbl_a_sequel(parse, exp, is_maj);
    my_printf_nbr_lpad(parse);
}
