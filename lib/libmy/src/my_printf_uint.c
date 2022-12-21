/*
** EPITECH PROJECT, 2022
** to manage unsigned int in printf
** File description:
** my_printf_uint
*/

#include "my_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

int my_printf_alt_fmt(my_printf_arg_t *parse)
{
    switch (parse->conv) {
        case (CONV_o):
            if (parse->data.value.integer != 0 && (parse->flags & ALT_FMT))
                parse->bytes_written += write(1, "0", 1);
            return 1;
        case (CONV_x):
            if (parse->data.value.integer != 0 && (parse->flags & ALT_FMT))
                parse->bytes_written += write(1, "0x", 2);
            return 2;
        case (CONV_X):
            if (parse->data.value.integer != 0 && (parse->flags & ALT_FMT))
                parse->bytes_written += write(1, "0X", 2);
            return 2;
    }
    return 0;
}

void my_printf_uint_getargs(my_printf_arg_t *parse, va_list ap)
{
    switch (parse->len) {
        default:
            my_printf_setint(parse, va_arg(ap, int), 0);
            break;
        case L_ll:
            my_printf_setint(parse, va_arg(ap, long long), 0);
            break;
        case L_l:
            my_printf_setint(parse, va_arg(ap, long), 0);
            break;
        case L_j:
            my_printf_setint(parse, va_arg(ap, intmax_t), 0);
            break;
        case L_z:
            my_printf_setint(parse, va_arg(ap, ssize_t), 0);
            break;
        case T_t:
            my_printf_setint(parse, va_arg(ap, ptrdiff_t), 0);
            break;
    }
}

static int my_printf_uint_base_r(uintmax_t val, int base, int is_maj)
{
    int bytes_written = 0;
    const char hexc[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};
    if (val == 0)
        return 0;
    bytes_written += my_printf_uint_base_r(val / base, base, is_maj);
    return (int) write(1, &hexc[is_maj][val % base], 1) + bytes_written;
}

void my_printf_nbr_base(my_printf_arg_t *parse)
{
    int is_maj = 0;
    if (parse->conv == CONV_X)
        is_maj = 1;
    *parse->bytes_written += my_printf_uint_base_r(parse->data.value.integer,
        parse->data.base, is_maj);
}

void my_printf_uint(my_printf_arg_t *parse, va_list ap)
{
    my_printf_uint_getargs(parse, ap);
    switch (parse->conv) {
        case CONV_o:
            parse->data.base = 8;
            break;
        case CONV_u:
            parse->data.base = 10;
            break;
        case CONV_b:
            parse->data.base = 2;
            break;
        case CONV_x...CONV_X:
            parse->data.base = 16;
            break;
    }
    my_printf_uint_sequel(parse);
}
