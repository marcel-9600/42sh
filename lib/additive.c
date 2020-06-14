/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

subs *modifier(char *str, int i)
{
    subs *sub_flags = malloc(sizeof(subs));
    sub_flags->nbr = 1;
    sub_flags->sign = '\0';
    sub_flags->padding = '\0';
    sub_flags->hashtag = '\0';
    sub_flags->len = 0;
    int match = 1;

    sub_flags = mod_loop(str, sub_flags, match, i);
    sub_flags->nbr /= 10;
    if (sub_flags->nbr != 0 && sub_flags->padding == '\0')
        sub_flags->padding = ' ';
    sub_flags->len -= 1;
    return (sub_flags);
}

subs *mod_loop(char *flags, subs *sub_flags, int match, int i)
{
    for (int j = i + 1; match; j += 1, sub_flags->len += 1) {
        match = 0;
        if (flags[j] == '+' || flags[j] == '-') {
            sub_flags->sign = flags[j];
            match = 1;
        }
        if (flags[j] == ' ' || flags[j] == '0') {
            sub_flags->padding = flags[j];
            match = 1;
        }
        if (flags[j] == '#') {
            sub_flags->hashtag = flags[j];
            match = 1;
        }
        if (flags[j] - 48 > 0 && flags[j] - 48 <= 9) {
            sub_flags->nbr *= (flags[j] - 48) * 10;
            match = 1;
        }
    }
    return (sub_flags);
}

int count_digit(unsigned int nbr)
{
    int counter = 0;

    while (nbr > 0) {
        counter += 1;
        nbr /= 10;
    }
    return (counter);
}

int count_base(unsigned int nbr, int len)
{
    int counter = 0;

    if (nbr == 0)
        return (1);
    else {
        while (nbr > 0) {
            nbr /= len;
            counter += 1;
        }
    }
    return (counter);
}

void put_d_flag(int nb, subs *sub)
{
    if (sub->sign == '+' && nb > 0)
        my_putchar('+');
    my_put_nbr(nb);
}
