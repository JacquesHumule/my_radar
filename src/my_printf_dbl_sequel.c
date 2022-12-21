/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-jacques.rathier
** File description:
** my_printf_dbl_f_sequel
*/

#include <unistd.h>
#include "my.h"
#include "my_printf.h"

void my_printf_dbl_e_sequel(my_printf_arg_t *parse, int exp, int is_maj)
{
    char expchar[2] = "eE";
    long double num = parse->data.value.floating;
    num /= my_compute_power_rec(parse->data.base, exp);
    int bef = (int) num;
    *parse->bytes_written += my_printf("%i", bef);
    int precis = parse->precision;
    uintmax_t aft = (uintmax_t) ((num - (long double) bef) *
    my_compute_power_rec(parse->data.base, precis));
    if (precis || parse->is_alt) {
        *parse->bytes_written += my_printf(".");
        int reste = precis - count_nbr(aft, parse->data.base, 0, CONV_i);
        while (reste > 0) {
            *parse->bytes_written += my_printf("0");
            reste--;
        }
        if (aft)
            *parse->bytes_written += my_printf("%i", aft);
    }
    *parse->bytes_written += write(1, &expchar[is_maj], 1);
    *parse->bytes_written += my_printf("%+.2i", exp);
}

void my_printf_dbl_a_sequel(my_printf_arg_t *parse, int exp, int is_maj)
{
    char expchar[2] = "pP";
    long double num = parse->data.value.floating;
    num /= my_compute_power_rec(parse->data.base, exp);
    uintmax_t bef = (uintmax_t) num;
    *parse->bytes_written += my_printf("%x", bef);
    int precis = parse->precision;
    uintmax_t aft = (uintmax_t) ((num - (long double) bef) *
    my_compute_power_rec(parse->data.base, precis));
    if (precis || parse->is_alt) {
        *parse->bytes_written += my_printf(".");
        int reste = precis - count_nbr(aft, parse->data.base, 0, CONV_i);
        while (reste > 0) {
            *parse->bytes_written += my_printf("0");
            reste--;
        }
        if (aft)
            *parse->bytes_written += my_printf("%x", aft);
    }
    *parse->bytes_written += write(1, &expchar[is_maj], 1);
    *parse->bytes_written += my_printf("+%+x", exp);
}

void my_printf_dbl_f_sequel(my_printf_arg_t *parse)
{
    long double num = parse->data.value.floating;
    if (num == 0)
        return (void) my_printf("0");
    uintmax_t bef = (uintmax_t) parse->data.value.floating;
    *parse->bytes_written += my_printf("%i", bef);

    int precis = parse->precision;
    uintmax_t aft = (uintmax_t) ((num - (long double) bef) *
    my_compute_power_rec(10, precis));
    if (precis || parse->flags & ALT_FMT) {
        *parse->bytes_written += my_printf(".");
        int reste = precis - count_nbr(aft, 10, 0, CONV_i);
        count_nbr(aft, parse->data.base, 0, CONV_i);
        while (reste > 0) {
            *parse->bytes_written += my_printf("0");
            reste--;
        }
        if (aft)
            *parse->bytes_written += my_printf("%i", aft);
    }
}
