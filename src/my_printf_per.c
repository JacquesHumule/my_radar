/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_per.c
*/

#include "my_printf.h"
#include <unistd.h>

void my_printf_percent(my_printf_arg_t *parse, va_list ap)
{
    *parse->bytes_written += (int) write(1, "%", 1);
}
