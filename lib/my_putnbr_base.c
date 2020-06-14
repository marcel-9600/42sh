/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** putnbr_from_base
*/

#include "../include/my.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int len_base = my_strlen(base);

    if (nbr == 0)
        return (0);
    else
        my_putnbr_base(nbr / len_base, base);
    my_putchar(base[nbr % len_base]);
    return (0);
}
