/*
** EPITECH PROJECT, 2019
** task 01
** File description:
** day 06
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strmcpy(char *dest, char const *src, int m)
{
    int j = 0;

    for (int i = m; src[i]; i += 1, j += 1)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}

char *my_strnmcpy(char *dest, char const *src, int m, int n)
{
    int j = 0;

    for (int i = m; i < n && src[i]; i += 1, j += 1)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}