##
## EPITECH PROJECT, 2022
## libmy
## File description:
## Makefile
##

SRC =	my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_is_prime.c \
		my_isneg.c \
		my_printf.c \
		my_printf_char.c \
		my_printf_dbl.c \
		my_printf_dbl_sequel.c \
		my_printf_dbl_suite.c \
		my_printf_getpad.c \
		my_printf_int.c \
		my_printf_n.c \
		my_printf_parse.c \
		my_printf_per.c \
		my_printf_str.c \
		my_printf_uint.c \
		my_printf_uint_sequel.c \
		my_printf_utils.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_sort_int_array.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c \
		linked_lists/linked_list.c \
		linked_lists/linked_list_2.c \
		linked_lists/linked_list_3.c
SRC:=	$(addprefix src/, $(SRC))

CPPFLAGS =	-Iinclude -O1

ARFLAGS =	rcs

OBJ =	$(SRC:.c=.o)

NAME =	../libmy.a

.NOTPARALLEL: all
all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib

lib: $(NAME)($(OBJ))

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.NOTPARALLEL: re
re: fclean all

.PHONY: all clean fclean re lib
