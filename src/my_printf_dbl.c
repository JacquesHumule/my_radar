/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_dbl.c
*/

#include "my_printf.h"
#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void my_printf_dbl_getargs(my_printf_arg_t *parse, va_list ap)
{
    switch (parse->len) {
        case L_L:
            my_printf_setflt(parse, va_arg(ap, long double));
            break;
        default:
            my_printf_setflt(parse, va_arg(ap, double));
            break;
    }
}

void my_printf_dbl_e(my_printf_arg_t *parse, va_list ap)
{
    int is_maj = 0;
    if (parse->conv == CONV_E)
        is_maj = 1;
    my_printf_dbl_getargs(parse, ap);
    int exp = float_exp(parse->data.value.floating, 10);
    int precis = (parse->precision < 0) ? 6 : parse->precision;
    parse->data.value.floating += 5l
        * my_compute_power_rec(10l, exp - precis - 1);
    parse->data.base = 10;
    my_printf_dbl_e_getpad(parse);
    my_printf_nbr_spad(parse);
    my_printf_nbr_zpad(parse);
    my_printf_dbl_e_sequel(parse, exp, is_maj);
    my_printf_nbr_lpad(parse);
}

void my_printf_dbl_f(my_printf_arg_t *parse, va_list ap)
{
    my_printf_dbl_getargs(parse, ap);
    int precis = (parse->precision < 0) ? 6 : parse->precision;
    parse->data.value.floating += 5l * my_compute_power_rec(10l, -precis - 1);
    parse->data.base = 10;
    my_printf_dbl_f_getpad(parse);
    my_printf_nbr_spad(parse);
    my_printf_nbr_zpad(parse);
    my_printf_dbl_f_sequel(parse);
    my_printf_nbr_lpad(parse);
}
