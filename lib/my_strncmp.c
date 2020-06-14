/*
** EPITECH PROJECT, 2019
** y
** File description:
** compares strings
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len_s2 = my_strlen(s2);
    int len_s1 = my_strlen(s1);

    if (len_s1 < len_s2 && len_s1 < n && len_s2 < n)
        return (1);
    else if (len_s2 < len_s1 && len_s1 < n && len_s2 < n)
        return (-1);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] ) {
            if (s1[i] > s2[i])
                return (-1);
            return (1);
        }
    }
    return (0);
}
