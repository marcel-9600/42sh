/*
** EPITECH PROJECT, 2019
** echo_clean.c
** File description:
** echo clean
*/

#include "../include/my.h"
#include <math.h>

void check_space(char c, int *space, int *set_space)
{
    if (c == ' ')
        *space = 1;
    else {
        *space = 0;
        *set_space = 0;
    }
}

int mcs_in_loop(int *qoute, char *new, char s, int *j)
{
    if (s == 34 || s == 39) ++*qoute;
    if (*qoute % 2 == 1) {
        new[*j] = s;
        ++*j;
        return 1;
    }
    return 0;
}

char *my_clean_string(char *s)
{
    char *new = NULL;
    int space = 0;
    int set_space = 0;
    int qoute = 0;
    int j = 0;

    if (!(new = malloc(sizeof(char) * my_strlen(s)))) exit(84);
    for (int i = 0; s[i]; i++) {
        if (mcs_in_loop(&qoute, new, s[i], &j) == 1) continue;
        check_space(s[i], &space, &set_space);
        if (space == 1 && set_space == 0) {
            new[j] = ' ';
            set_space = 1;
        } else if (space == 1) continue;
        else {
            new[j] = s[i];
            set_space = 0;
        }
        j++;
    }
    return new;
}

int oct_to_dec(int o)
{
    int d = 0;

    for (int i = 0; o != 0; i++) {
        d = d + (o % 10) * pow(8, i);
        o /= 10;
    }
    return d;
}

int get_oct_num(char *new, int i)
{
    char *tmp = NULL;
    char *tmp_t = NULL;
    int num = 0;

    if (!(tmp = malloc(sizeof(char) * my_strlen(new))))
        exit(84);
    if (!(tmp_t = malloc(sizeof(char) * 4)))
        exit(84);
    tmp = strcpy(tmp, new);
    tmp += i + 1;
    tmp_t = strncpy(tmp_t, tmp, 4);
    num = my_getnbr(tmp_t);
    num = oct_to_dec(num);
    free(tmp_t);
    return num;
}
