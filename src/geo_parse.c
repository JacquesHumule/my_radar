/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** geo_parse.c
*/

#include "geo_parse.h"
#include <stdbool.h>
#include <stdlib.h>

bool check_geo(char const *str)
{
    if (str == NULL)return false;
    int nb_long, nb_lat;
    if (str[0] != '-' && str[0] != '+') return false;
    for (nb_lat = 1; str[nb_lat] != '-' && str[nb_lat] != '+'; nb_lat++) {
        if (str[nb_lat] == '\0')
            return false;
        if (IS_NUM(str[nb_lat]) == false)
            return false;
    }
    for (nb_long = nb_lat + 1; str[nb_long] != '-' && str[nb_long] != '+';
    nb_long++) {
        if (str[nb_long] == '\0')
            return false;
        if (IS_NUM(str[nb_long]) == false)
            break;
    }
    if ((nb_lat - 1) % 2 != 0 || nb_long % 2 != 1)
        return false;
    return true;
}

float lat_parse(char const * str)
{
    short neg = 1, deg = 0, min = 0, sec = 0, cur = 1;
    if (*str != '-' && *str != '+')
        return 84;
    if (*str == '-') {
        neg = -1;
    }
    for (; cur <= 2 && IS_NUM(str[cur]); cur++) deg = deg * 10 + str[cur] - '0';
    for (; cur <= 4 && IS_NUM(str[cur]); cur++) min = min * 10 + str[cur] - '0';
    for (; cur <= 6 && IS_NUM(str[cur]); cur++) sec = sec * 10 + str[cur] - '0';
    if (cur == 3)
        return (float) (deg * neg);
    if (cur == 5)
        return (float) (deg * neg) + (float) min / 60;
    if (cur == 7)
        return (float) (deg * neg) + (float) min / 60 + (float) sec / 3600;
    return 0;
}

float long_parse(char const * str)
{
    short neg = 1, deg = 0, min = 0, sec = 0, cur = 1;
    if (*str != '-' && *str != '+')
        return 84;
    if (*str == '-') {
        neg = -1;
    }
    for (; cur <= 3 && IS_NUM(str[cur]); cur++) deg = deg * 10 + str[cur] - '0';
    for (; cur <= 5 && IS_NUM(str[cur]); cur++) min = min * 10 + str[cur] - '0';
    for (; cur <= 7 && IS_NUM(str[cur]); cur++) sec = sec * 10 + str[cur] - '0';
    if (cur == 4)
        return (float) (deg * neg);
    if (cur == 6)
        return (float) (deg * neg) + (float) min / 60;
    if (cur == 8)
        return (float) (deg * neg) + (float) min / 60 + (float) sec / 3600;
    return 0;
}
