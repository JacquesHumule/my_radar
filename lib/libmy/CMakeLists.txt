cmake_minimum_required(VERSION 3.23)
project(my LANGUAGES C VERSION 0.2 DESCRIPTION "Lib for Epitech")

set(CMAKE_C_STANDARD 99)

include_directories(include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")


add_library(my
        src/my_compute_power_rec.c
        src/my_compute_square_root.c
        src/my_find_prime_sup.c
        src/my_getnbr.c
        src/my_is_prime.c
        src/my_isneg.c
        src/my_printf.c
        src/my_printf_char.c
        src/my_printf_dbl.c
        src/my_printf_dbl_sequel.c
        src/my_printf_dbl_suite.c
        src/my_printf_getpad.c
        src/my_printf_int.c
        src/my_printf_n.c
        src/my_printf_parse.c
        src/my_printf_per.c
        src/my_printf_str.c
        src/my_printf_uint.c
        src/my_printf_uint_sequel.c
        src/my_printf_utils.c
        src/my_put_nbr.c
        src/my_putchar.c
        src/my_putstr.c
        src/my_revstr.c
        src/my_showmem.c
        src/my_showstr.c
        src/my_sort_int_array.c
        src/my_str_isalpha.c
        src/my_str_islower.c
        src/my_str_isnum.c
        src/my_str_isprintable.c
        src/my_str_isupper.c
        src/my_strcapitalize.c
        src/my_strcat.c
        src/my_strcmp.c
        src/my_strcpy.c
        src/my_strlen.c
        src/my_strlowcase.c
        src/my_strncat.c
        src/my_strncmp.c
        src/my_strncpy.c
        src/my_strstr.c
        src/my_strupcase.c
        src/my_swap.c
        src/linked_lists/linked_list.c
        src/linked_lists/linked_list_2.c
        src/linked_lists/linked_list_3.c)
