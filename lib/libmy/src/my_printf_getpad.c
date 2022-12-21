/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_getpad.c
*/

#include "my_printf.h"

void my_printf_int_getpad(my_printf_arg_t *parse)
{
    int pad_left = (parse->flags & PAD_LEFT) > 0;
    parse->SPACING.nbr_size = count_nbr(parse->data.value.integer,
        parse->data.base, parse->is_alt, parse->conv);
    parse->SPACING.sign = ((parse->data.neg == 1) || (parse->flags & (SIGN_SPACE
        + SIGN_PLUS)) > 0) && parse->data.is_signed;
    int base_pad = parse->width - parse->SPACING.nbr_size - parse->SPACING.sign;
    if (parse->precision < 0 && parse->flags & PAD_ZERO)
        parse->SPACING.zpad = base_pad;
    else {
        parse->SPACING.zpad = parse->precision - parse->SPACING.nbr_size;
        if (parse->SPACING.zpad < 0)
            parse->SPACING.zpad = 0 + parse->data.value.integer == 0;
    }
    parse->SPACING.spad = (base_pad - parse->SPACING.zpad) * !pad_left;
    parse->SPACING.lpad = (base_pad - parse->SPACING.zpad) * pad_left;
}

void my_printf_dbl_f_getpad(my_printf_arg_t *parse)
{
    int pad_left = (parse->flags & PAD_LEFT) > 0;
    int pad_zero = (parse->flags & PAD_ZERO) > 0;
    parse->SPACING.nbr_size = count_nbr((uintmax_t) parse->data.value.floating,
        parse->data.base, parse->is_alt, parse->conv);
    if ((uintmax_t) parse->data.value.floating == 0)
        parse->SPACING.nbr_size += 1 + parse->is_alt;
    if (parse->precision < 0) {
        parse->precision = 6;
    }
    if (parse->precision > 0) {
        parse->SPACING.nbr_size += 1 + parse->precision;
    }
    parse->SPACING.sign = ((parse->data.neg == 1) || (parse->flags & (SIGN_SPACE
        + SIGN_PLUS)) > 0) && parse->data.is_signed;
    int base_pad = parse->width - parse->SPACING.sign - parse->SPACING.nbr_size;
    parse->SPACING.spad = base_pad * !pad_zero * !pad_left;
    parse->SPACING.zpad = base_pad * pad_zero * !pad_left;
    parse->SPACING.lpad = base_pad * pad_left;
}

void my_printf_dbl_e_getpad(my_printf_arg_t *parse)
{
    int pad_left = (parse->flags & PAD_LEFT) > 0;
    int pad_zero = (parse->flags & PAD_ZERO) > 0;
    int exp_size = count_nbr(float_exp(parse->data.value.floating,
        parse->data.base), parse->data.base, 0, CONV_i);
    if (exp_size < 2)
        exp_size = 2;
    parse->SPACING.nbr_size = 3 + exp_size;
    if (parse->precision < 0)
        parse->precision = 6;
    if (parse->precision > 0)
        parse->SPACING.nbr_size += 1 + parse->precision;
    if (parse->precision == 0 && parse->is_alt)
        parse->SPACING.nbr_size++;
    parse->SPACING.sign = ((parse->data.neg == 1) || (parse->flags & (SIGN_SPACE
        + SIGN_PLUS)) > 0) && parse->data.is_signed;
    int base_pad = parse->width - parse->SPACING.sign - parse->SPACING.nbr_size;
    parse->SPACING.spad = base_pad * !pad_zero * !pad_left;
    parse->SPACING.zpad = base_pad * pad_zero * !pad_left;
    parse->SPACING.lpad = base_pad * pad_left;
}

void my_printf_dbl_a_getpad(my_printf_arg_t *parse)
{
    int pad_left = (parse->flags & PAD_LEFT) > 0;
    int pad_zero = (parse->flags & PAD_ZERO) > 0;
    int exp_size = count_nbr(float_exp(parse->data.value.floating,
        parse->data.base), parse->data.base, 0,
        CONV_i);
    if (exp_size < 2)
        exp_size = 2;
    parse->SPACING.nbr_size = 3 + exp_size;
    if (parse->precision < 0)
        parse->precision = 6;
    if (parse->precision > 0)
        parse->SPACING.nbr_size += 1 + parse->precision;
    if (parse->precision == 0 && parse->is_alt)
        parse->SPACING.nbr_size++;
    parse->SPACING.sign = ((parse->data.neg == 1) || (parse->flags & (SIGN_SPACE
        + SIGN_PLUS)) > 0) && parse->data.is_signed;
    int base_pad = parse->width - parse->SPACING.sign - parse->SPACING.nbr_size;
    parse->SPACING.spad = base_pad * !pad_zero * !pad_left;
    parse->SPACING.zpad = base_pad * pad_zero * !pad_left;
    parse->SPACING.lpad = base_pad * pad_left;
}
