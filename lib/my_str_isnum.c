/*
** EPITECH PROJECT, 2019
** y
** File description:
** is a num
*/

#include "../include/my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            if (str[i] != '+' && str[i] != '-')
                return (0);
    }
    return (1);
}
