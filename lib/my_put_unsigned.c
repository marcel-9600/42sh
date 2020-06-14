/*
** EPITECH PROJECT, 2019
** nice
** File description:
** put_unisgned
*/

#include "../include/my.h"

int my_put_unsigned(unsigned int nb)
{
    unsigned int mod;

    if (nb >= 10) {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar(mod + 48);
    } else
        my_putchar(nb % 10 + 48);
    return (0);
}
