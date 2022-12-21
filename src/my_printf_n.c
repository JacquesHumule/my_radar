/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_n.c
*/

#include "my_printf.h"

void my_printf_n(my_printf_arg_t *parse, va_list ap)
{
    int *out = va_arg(ap, void *);
    *out = *parse->bytes_written;
}
