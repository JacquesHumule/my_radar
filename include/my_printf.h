/*
** EPITECH PROJECT, 2022
** flags prototypes
** File description:
** pointeurs sur fonctions
*/



#ifndef MY_PRINTF_
    #define MY_PRINTF_

    #include <stdarg.h>

    #include <stdint.h>

    #define PAD_ZERO (1 << 1)
    #define PAD_LEFT (1 << 2)
    #define SIGN_SPACE (1 << 3)
    #define SIGN_PLUS (1 << 4)
    #define ALT_FMT (1 << 0)
    #define SPACING data.pad

typedef enum my_printf_len_e {
    L_hh,
    L_h,
    L_ll,
    L_l,
    L_L,
    L_j,
    L_z,
    T_t,
    L_
} my_printf_len_t;
typedef enum my_printf_conv_e {
    CONV_d, CONV_i, CONV_o, CONV_u, CONV_b, CONV_x, CONV_X, CONV_e, CONV_E,
    CONV_f, CONV_F, CONV_g, CONV_G, CONV_a, CONV_A, CONV_c, CONV_s, CONV_S,
    CONV_p, CONV_n, CONV_per
} my_printf_conv_t;
union value_u {
    uintmax_t integer;
    long double floating;
};
typedef struct my_printf_value_s {
    struct {
        int spad;
        unsigned int sign : 1;
        int zpad;
        int nbr_size;
        int lpad;
    } pad;
    union value_u value;
    unsigned int is_signed : 1;
    unsigned int neg : 1;
    int base;
} my_printf_value_t;
typedef struct my_printf_arg_s {
    int flags;
    unsigned int is_alt : 1;
    int width;
    int precision;
    my_printf_len_t len;
    my_printf_conv_t conv;
    my_printf_value_t data;
    int * bytes_written;
} my_printf_arg_t;
extern void (*conversion_fx[21])(my_printf_arg_t *parse, va_list ap);
int count_nbr(uintmax_t nbr, int base, int is_alt, my_printf_conv_t conv);
int float_exp(long double nb, int base);
int my_char_isnum(char c);
int my_printf_alt_fmt(my_printf_arg_t *parse);
int my_printf_conversions(char **str);
int my_printf_flags(char **str);
int my_printf_length(char **str);
int my_printf_precision(char **str);
int my_printf_width(char **str);
void my_printf_char(my_printf_arg_t *parse, va_list ap);
void my_printf_dbl_a(my_printf_arg_t *parse, va_list ap);
void my_printf_dbl_a_getpad(my_printf_arg_t *parse);
void my_printf_dbl_a_sequel(my_printf_arg_t *parse, int exp, int is_maj);
void my_printf_dbl_e(my_printf_arg_t *parse, va_list ap);
void my_printf_dbl_e_getpad(my_printf_arg_t *parse);
void my_printf_dbl_e_sequel(my_printf_arg_t *parse, int exp, int is_maj);
void my_printf_dbl_f(my_printf_arg_t *parse, va_list ap);
void my_printf_dbl_f_getpad(my_printf_arg_t *parse);
void my_printf_dbl_f_sequel(my_printf_arg_t *parse);
void my_printf_dbl_g(my_printf_arg_t *parse, va_list ap);
void my_printf_dbl_getargs(my_printf_arg_t *parse, va_list ap);
void my_printf_int(my_printf_arg_t *parse, va_list ap);
void my_printf_int_getargs(my_printf_arg_t *parse, va_list ap);
void my_printf_int_getpad(my_printf_arg_t *parse);
void my_printf_nbr_base(my_printf_arg_t *parse);
void my_printf_nbr_lpad(my_printf_arg_t *parse);
void my_printf_nbr_spad(my_printf_arg_t *parse);
void my_printf_nbr_zpad(my_printf_arg_t *parse);
void my_printf_n(my_printf_arg_t *parse, va_list ap);
void my_printf_percent(my_printf_arg_t *parse, va_list ap);
void my_printf_setflt(my_printf_arg_t *parse, long double nbr);
void my_printf_setint(my_printf_arg_t *parse, intmax_t nbr, int is_signed);
void my_printf_str(my_printf_arg_t *parse, va_list ap);
void my_printf_uint(my_printf_arg_t *parse, va_list ap);
void my_printf_uint_getargs(my_printf_arg_t *parse, va_list ap);
void my_printf_uint_sequel(my_printf_arg_t *parse);
#endif //MY_PRINTF_
