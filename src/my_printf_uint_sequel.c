/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-jacques.rathier
** File description:
** my_printf_uint_sequel
*/

#include "my_printf.h"

void my_printf_uint_sequel(my_printf_arg_t *parse)
{
    my_printf_int_getpad(parse);
    my_printf_nbr_spad(parse);
    my_printf_nbr_zpad(parse);
    my_printf_alt_fmt(parse);
    my_printf_nbr_base(parse);
    my_printf_nbr_lpad(parse);
}
