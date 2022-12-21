/*
** EPITECH PROJECT, 2022
** to manage chars in printf
** File description:
** my_printf_char
*/

#include "my_printf.h"
#include <stdarg.h>
#include <unistd.h>

void my_printf_char(my_printf_arg_t *parse, va_list ap)
{
    parse->bytes_written += 1;
    unsigned char c = (unsigned char) va_arg(ap, int);
    write (1, &c, 1);
}
