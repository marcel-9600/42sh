/*
** EPITECH PROJECT, 2019
** prompt.c
** File description:
** lsls
*/

#include "../include/my.h"

void prompt(var_t *envp)
{
    int get_user = 0;
    if (isatty(0) == 0)
        return;
    var_t *tmp = envp;

    while (tmp) {
        if (my_strcmp(tmp->name, "USER") == 0) {
            get_user = 1;
            my_printf("[%s", tmp->value);
        }
        tmp = tmp->next;
    }
    if (get_user == 0)
        my_printf("[no user found");
    my_printf("@42sh]$ ");
}
