/*
** EPITECH PROJECT, 2019
** dup
** File description:
** dup a string
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(dest, src);
    dest[my_strlen(src)] = '\0';
    return (dest);
}
