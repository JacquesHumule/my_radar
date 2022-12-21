/*
** EPITECH PROJECT, 2022
** strcmp
** File description:
** zefjhezf
*/

int my_strcmp(char const *stra, char const *strb)
{
    int i = 0;
    while (stra[i] == strb[i] && stra[i] != '\0')
        i++;
    if (stra[i] - strb[i] < 0)
        return -1;
    if (stra[i] - strb[i] > 0)
        return 1;
    return 0;
}
