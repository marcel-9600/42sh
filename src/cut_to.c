/*
** EPITECH PROJECT, 2019
** echo.c
** File description:
** echo
*/

#include "../include/my.h"

int cut_from(char *s)
{
    int n;
    int m = 0;

    for (int i = 33; i < 127; i++) {
        n = count_from(s, i);
        if (n != -1 && n > m) m = n;
    }
    return m;
}

int cut_to(char *s)
{
    int n;
    int m = 1000;

    for (int i = 33; i < 127; i++) {
        n = count_to(s, i);
        if (n != -1 && n < m) m = n;
    }
    return m;
}

int echo_error(int which_qoute, int qoutes)
{
    if (qoutes % 2 != 0) {
        fprintf(stderr, "Unmatched %c%c%c.\n", 39, which_qoute, 39);
        return 1;
    }
    return 0;
}
