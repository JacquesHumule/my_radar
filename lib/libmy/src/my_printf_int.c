/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_int.c
*/

#include "my_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

void my_printf_int_getargs(my_printf_arg_t *parse, va_list ap)
{
    switch (parse->len) {
        default:
            my_printf_setint(parse, va_arg(ap, int), 1);
            break;
        case L_ll:
            my_printf_setint(parse, va_arg(ap, long long), 1);
            break;
        case L_l:
            my_printf_setint(parse, va_arg(ap, long), 1);
            break;
        case L_j:
            my_printf_setint(parse, va_arg(ap, intmax_t), 1);
            break;
        case L_z:
            my_printf_setint(parse, va_arg(ap, ssize_t), 1);
            break;
        case T_t:
            my_printf_setint(parse, va_arg(ap, ptrdiff_t), 1);
            break;
    }
}

void my_printf_nbr_spad(my_printf_arg_t *parse)
{
    int bytes_written = 0;
    int sign = 0;
    if (parse->flags & SIGN_SPACE)
        sign = ' ';
    if (parse->flags & SIGN_PLUS)
        sign = '+';
    if (parse->data.neg)
        sign = '-';
    for (int i = parse->SPACING.spad; i > 0; i--)
        bytes_written += (int) write(1, " ", 1);
    if (parse->SPACING.sign) {
        bytes_written += (int) write(1, &sign, 1);
        parse->width--;
    }
    *parse->bytes_written += bytes_written;
}

void my_printf_nbr_zpad(my_printf_arg_t *parse)
{
    int bytes_written = 0;
    for (int i = parse->SPACING.zpad; i > 0; i--)
        bytes_written += write(1, "0", 1);
    *parse->bytes_written += bytes_written;
}

void my_printf_nbr_lpad(my_printf_arg_t *parse)
{
    int byte_written = 0;
    for (int i = parse->SPACING.lpad; i > 0 && parse->flags & PAD_LEFT; i--)
        byte_written += (int) write(1, " ", 1);
    *parse->bytes_written += byte_written;
}

void my_printf_int(my_printf_arg_t *parse, va_list ap)
{
    my_printf_int_getargs(parse, ap);
    parse->data.base = 10;
    my_printf_int_getpad(parse);
    my_printf_nbr_spad(parse);
    my_printf_nbr_zpad(parse);
    my_printf_nbr_base(parse);
    my_printf_nbr_lpad(parse);
}
