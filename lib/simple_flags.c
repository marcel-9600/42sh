/*
** EPITECH PROJECT, 2019
** simple_flags
** File description:
** types
*/

#include "../include/my.h"

int s_flag(va_list list, subs *sub)
{
    int counter = sub->nbr;
    char *str = va_arg(list, char *);

    if (sub->padding && sub->sign != '-') {
        while (counter > my_strlen(str)) {
            my_putchar(' ');
            counter -= 1;
        }
        my_putstr(str);
    }
    else if (sub->padding && sub->sign == '-') {
        my_putstr(str);
        while (counter > my_strlen(str)) {
            my_putchar(' ');
            counter -= 1;
        }
    }
    else
        my_putstr(str);
    return (0);
}

int c_flag(va_list list, subs *sub)
{
    int counter = sub->nbr;

    if (sub->padding && sub->sign != '-') {
        while (counter > 1) {
            my_putchar(' ');
            counter -= 1;
        }
        my_putchar(va_arg(list, int));
    }
    else if (sub->padding && sub->sign == '-') {
        my_putchar(va_arg(list, int));
        while (counter > 1) {
            my_putchar(' ');
            counter -= 1;
        }
    }
    else
        my_putchar(va_arg(list, int));
    return (0);
}

int d_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, int);
    int len = count_digit(nb);

    if (nb < 0)
        len += 1;
    if (sub->padding && sub->sign != '-') {
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(sub->padding);
        put_d_flag(nb, sub);
    }
    else if (sub->padding && sub->sign == '-') {
        put_d_flag(nb, sub);
        for (int counter = sub->nbr; counter > len; counter -= 1)
            my_putchar(' ');
    }
    else
        put_d_flag(nb, sub);
    return (0);
}

int u_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, unsigned int);
    int counter = sub->nbr;

    if (sub->padding == '0' && sub->sign != '-') {
        while (counter > count_digit(nb)) {
            my_putchar(sub->padding);
            counter -= 1;
        }
        my_put_unsigned(nb);
    }
    else if (sub->padding && sub->sign == '-') {
        my_put_unsigned(nb);
        while (counter > count_digit(nb)) {
            my_putchar(' ');
            counter -= 1;
        }
    }
    else
        my_put_unsigned(nb);
    return (0);
}

int percent_flag(va_list list, subs *sub)
{
    int nb = va_arg(list, int);
    my_putchar('%');
    if (sub->sign == '-')
        nb = 0;
    nb = 1;
    return (nb);
}
