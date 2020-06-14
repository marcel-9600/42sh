/*
** EPITECH PROJECT, 2019
** i
** File description:
** slkdjf
*/

#include "../include/my.h"

int count_to(char *s, char f)
{
    for (int i = 0; s[i]; i++) {
        if (s[i] == f) return i;
    }
    return -1;
}

int count_from(char *s, char f)
{
    for (int i = my_strlen(s) - 1; i >= 0; i--) {
        if (s[i] == f) return i;
    }
    return -1;
}
