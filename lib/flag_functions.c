/*
** EPITECH PROJECT, 2019
** flag
** File description:
** functions
*/

#include "../include/my.h"

char *to_oct(char c)
{
    char *new = malloc(sizeof(char) * 4);

    for (int i = 0; i <= 2; i += 1) {
        new[i] = '0';
    }
    new[3] = '\0';
    for (int j = 2; j >= 0; j -= 1) {
        new[j] = c % 8 + 48;
        c /= 8;
    }
    return (new);
}

void put_cap_s(char *str)
{
    char *nbr;

    for (int i = 0; i < my_strlen(str); i += 1) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            nbr = to_oct(str[i]);
            my_putstr(nbr);
            free(nbr);
        } else {
            my_putchar(str[i]);
        }
    }
}

int cap_s_flag(va_list list, subs *sub)
{
    int counter = sub->nbr;
    char *str = va_arg(list, char *);

    if (sub->padding && sub->sign != '-') {
        while (counter > my_strlen(str)) {
            my_putchar(' ');
            counter -= 1;
        }
        put_cap_s(str);
    }
    else if (sub->padding && sub->sign == '-') {
        put_cap_s(str);
        while (counter > my_strlen(str)) {
            my_putchar(' ');
            counter -= 1;
        }
    }
    else
        put_cap_s(str);
    return (0);
}

int p_flag(va_list list, subs *sub)
{
    long long nb = va_arg(list, long long);
    int len = count_base(nb, 16);
    int counter = sub->nbr - 2;
    if (sub->padding == '0')
        my_putstr("0x");
    if (sub->padding && sub->sign == '-')
        p_flag_2(sub, nb);
    else if (sub->padding && sub->sign != '-') {
        while (counter > len) {
            my_putchar(sub->padding);
            counter -= 1;
        }
        if (sub->padding != '0')
            my_putstr("0x");
        my_putnbr_base(nb, "0123456789abcdef");
    } else {
        if (sub->padding != '0')
            my_putstr("0x");
        my_putnbr_base(nb, "0123456789abcdef");
    }
    return (0);
}
