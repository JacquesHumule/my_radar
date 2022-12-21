/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** qsdqdsqfd
*/

static int my_isalpha(char c)
{
    if (c >= 48 && c <= 57)
        return 0;
    if (c >= 65 && c <= 90)
        return 0;
    if (c >= 97 && c <= 'z')
        return 1;
    return -1;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (my_isalpha(str[i - 1]) == -1 && my_isalpha(str[i]) == 1 )
            str[i] -= 32;
    i++;
    }
    return str;
}
