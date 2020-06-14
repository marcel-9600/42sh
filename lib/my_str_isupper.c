/*
** EPITECH PROJECT, 2019
** is uppercase
** File description:
** string
*/

#include "../include/my.h"

int my_str_isupper(char const *str)
{
    int bool = 1;

    for (int i = 0; str[i]; i += 1)
        if (str[i] < 'A' || str[i] > 'Z')
            bool = 0;
    return (bool);
}
