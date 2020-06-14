/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

var_t *unset_env(var_t *envp, int argc, char **input, int *ret)
{
    var_t *tmp = envp;

    if (argc < 2) {
        *ret = 84;
        my_errputstr("unsetenv: Too few arguments.\n");
    }
    else {
        for (int i = 1; input[i]; i += 1) {
            tmp = envp;
            for (; my_strcmp(tmp->next->name, input[i]) != 0 && tmp->next->next;
            tmp = tmp->next);
            if (tmp->next->next == NULL &&
                my_strcmp(tmp->next->name, input[i]) != 0)
                return (envp);
            else
                tmp->next = tmp->next->next;
        }
    }
    return (envp);
}