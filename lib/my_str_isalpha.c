/*
** EPITECH PROJECT, 2019
** y
** File description:
** if is alphanumeric
*/

#include "../include/my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i += 1)
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
        && (str[i] < '0' || str[i] > '9') && str[i] != '_' && str[i] != '.')
            return (0);
    return (1);
}
