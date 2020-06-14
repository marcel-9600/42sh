/*
** EPITECH PROJECT, 2019
** base
** File description:
** flags
*/

#include "../include/my.h"

int b_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, unsigned int);
    int len = count_base(nb, 2);

    if (sub->padding && sub->sign != '-') {
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(sub->padding);
        my_putnbr_base(nb, "01");
    }
    else if (sub->padding && sub->sign == '-') {
        my_putnbr_base(nb, "01");
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(sub->padding);
    }
    else
        my_putnbr_base(nb, "01");
    return (0);
}

int x_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, unsigned int);
    int len = count_base(nb, 16);

    if (sub->hashtag) {
        if (sub->padding == '0')
            my_putstr("0x");
        len += 2;}
    if (sub->padding && sub->sign != '-') {
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(sub->padding);
        put_x_flag(sub, nb);
    }
    else if (sub->padding && sub->sign == '-') {
        put_x_flag(sub, nb);
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(' ');
    }
    else
        put_x_flag(sub, nb);
    return (0);
}

int cap_x_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, unsigned int);
    int len = count_base(nb, 16);

    if (sub->hashtag) {
        if (sub->padding == '0')
            my_putstr("0X");
        len += 2;}
    if (sub->padding && sub->sign != '-') {
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(sub->padding);
        put_cap_x_flag(sub, nb);
    }
    else if (sub->padding && sub->sign == '-') {
        put_cap_x_flag(sub, nb);
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(' ');
    }
    else
        put_cap_x_flag(sub, nb);
    return (0);
}

int o_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, unsigned int);
    int len = count_base(nb, 8);

    if (sub->hashtag) {
        if (sub->padding == '0')
            my_putstr("0");
        len += 1;}
    if (sub->padding && sub->sign != '-') {
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(sub->padding);
        put_o_flag(sub, nb);
    }
    else if (sub->padding && sub->sign == '-') {
        put_o_flag(sub, nb);
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(' ');
    }
    else
        put_o_flag(sub, nb);
    return (0);
}
