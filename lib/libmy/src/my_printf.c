/*
** EPITECH PROJECT, 2022
** printf project
** File description:
** reproduce printf behavior
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

void (*conversion_fx[21])(my_printf_arg_t *parse, va_list ap) = {
    &my_printf_int,
    &my_printf_int,
    &my_printf_uint,
    &my_printf_uint,
    &my_printf_uint,
    &my_printf_uint,
    &my_printf_uint,
    &my_printf_dbl_e,
    &my_printf_dbl_e,
    &my_printf_dbl_f,
    &my_printf_dbl_f,
    &my_printf_dbl_g,
    &my_printf_dbl_g,
    &my_printf_dbl_a,
    &my_printf_dbl_a,
    &my_printf_char,
    &my_printf_str,
    NULL,              // p
    NULL,             // n
    &my_printf_n,
    &my_printf_percent
};

my_printf_arg_t my_printf_parse(char **str, int * const nbr, va_list ap)
{
    my_printf_arg_t out = {
        .flags = my_printf_flags(str),
        .is_alt = (out.flags & ALT_FMT) > 0,
        .width = my_printf_width(str),
        .precision = my_printf_precision(str),
        .len = my_printf_length(str),
        .conv = my_printf_conversions(str),
        .bytes_written = nbr
    };
    return out;
}

int my_printf(char *str, ...)
{
    int sum = 0;
    va_list ap;
    va_start(ap, str);
    while (*str) {
        if (*str == '%') {
            str++;
            my_printf_arg_t parse = my_printf_parse(&str, &sum, ap);
            conversion_fx[parse.conv](&parse, ap);
        } else {
            int written = (int) write(1, str, 1);
            sum = (written < 0 || sum < 0) ? (-1) : (sum + written);
            str++;
        }
    }
    va_end(ap);
    return sum;
}
