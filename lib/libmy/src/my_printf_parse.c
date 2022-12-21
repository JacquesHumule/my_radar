/*
** EPITECH PROJECT, 2022
** B_CPE_101_BDX_1_1_myprintf_jacques_rathier
** File description:
** my_printf_parse.c
*/

#include "my_printf.h"
#include "my.h"

int my_printf_flags(char **str)
{
    const char flags_name[6] = "#0- +\0";
    int flags = 0;
    for (int j = 1; j; *str += j) {
        int flag = 0;
        for (int i = 0; flags_name[i]; i++)
            flag |= (flags_name[i] == **str) << i;
        flags |= flag;
        j = (flag) ? 1 : 0;
    }
    return flags;
}

int my_printf_width(char **str)
{
    int width = 0;
    for (; my_char_isnum(**str); *str += 1)
        width = width * 10 + (**str - '0');
    return width;
}

int my_printf_precision(char **str)
{
    int precision = 0;
    if (**str != '.')
        return -1;
    *str += 1;
    for (; my_char_isnum(**str); *str += 1)
        precision = precision * 10 + (**str - '0');
    return precision;
}

int my_printf_length(char **str)
{
    int len_mod = 0;
    const char *len_name[10] = {"hh\0", "h\0", "ll\0", "l\0", "L\0", "j\0",
        "z\0", "t\0", "\0"};
    for (; my_strncmp(*str, len_name[len_mod], my_strlen(len_name[len_mod]))
        && len_mod < 8; len_mod++);
    *str += my_strlen(len_name[len_mod]);
    return len_mod;
}

int my_printf_conversions(char **str)
{
    const char conv_name[21] = {'d', 'i', 'o', 'u', 'b', 'x', 'X', 'e', 'E',
        'f', 'F', 'g', 'G', 'a', 'A', 'c', 's', 'S', 'p', 'n', '%'};
    int conv;
    for (conv = 0; conv_name[conv] && conv_name[conv] != **str; conv++);
    *str += (conv == 23) ? 0 : 1;
    return conv;
}
