/*
** EPITECH PROJECT, 2019
** y
** File description:
** is_lower
*/

#include "../include/my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] >= 'a' && str[i] <= 'z')
        i += 1;
    if (i == my_strlen(str))
        return (1);
    return (0);
}
