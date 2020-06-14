/*
** EPITECH PROJECT, 2019
** concat
** File description:
** params
*/

#include "../include/my.h"

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int l = 0;
    char *new = (char *) malloc(sizeof(char) * (get_len(argc, argv) + argc));

    for (i = 0; i < argc; i++) {
        for (j = 0; j < my_strlen(argv[i]); j++) {
            new[l] = argv[i][j];
            l++;
        }
        new[l] = '\n';
        l++;
        j = 0;
    }
    return (new);
}

int get_len(int argc, char **argv)
{
    int len;

    for (int i = 0; i < argc; i++)
        len += my_strlen(argv[i]);
    return (len);
}
