/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** qsdmlk
*/

int my_str_isalpha(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 65)
            return 0;
        if (str[i] > 90 && str[i] < 97)
            return 0;
        if (str[i] > 122)
            return 0;
        i++;
    }
    return 1;
}
