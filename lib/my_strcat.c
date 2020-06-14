/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i += 1;
    }
    dest[len + i] = '\0';
    return (dest);
}

char *my_malloc_strcat(char *dest, char const *src)
{
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int len = my_strlen(dest);

    new = my_strcpy(new, dest);
    for (int j = 0; src[j]; j += 1)
        new[len + j] = src[j];
    new[my_strlen(dest) + my_strlen(src)] = '\0';
    return (new);
}