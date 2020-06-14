/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int p_flag_2(subs *sub, long long nb)
{
    int counter = sub->nbr - 2;

    if (sub->padding != '0')
        my_putstr("0x");
    my_putnbr_base(nb, "0123456789abcdef");
    while (counter > count_digit(nb)) {
        my_putchar(' ');
        counter -= 1;
    }
    return (0);
}

int put_x_flag(subs *sub, unsigned int nb)
{
    if (sub->hashtag && sub->padding != '0')
        my_putstr("0x");
    my_putnbr_base(nb, "0123456789abcdef");
    return (0);
}

int put_cap_x_flag(subs *sub, unsigned int nb)
{
    if (sub->hashtag && sub->padding != '0')
        my_putstr("0X");
    my_putnbr_base(nb, "0123456789ABCDEF");
    return (0);
}

int put_o_flag(subs *sub, unsigned int nb)
{
    if (sub->hashtag && sub->padding != '0')
        my_putstr("0");
    my_putnbr_base(nb, "01234567");
    return (0);
}

int count_args(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '%') {
            counter += 1;
        }
    }
    return (counter);
}
