/*
** EPITECH PROJECT, 2022
** to manage str in printf
** File description:
** my_printf_str
*/

#include "my_printf.h"
#include "my.h"
#include <stdarg.h>

void my_printf_str(my_printf_arg_t *parse, va_list ap)
{
    char *str = va_arg(ap, char *);
    parse->bytes_written += my_strlen(str);
    my_putstr(str);
}
