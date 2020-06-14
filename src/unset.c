/*
** EPITECH PROJECT, 2019
** unset.c
** File description:
** unset
*/

#include "../include/my.h"

void find_in_var(var_t *var, char *find)
{
    var_t *ptr = NULL;

    for (ptr = var; ptr->next; ptr = ptr->next) {
        if (ptr->next->next == NULL && strcmp(find, ptr->next->name) == 0) {
            ptr->next = NULL;
            return;
        }
        if (strcmp(find, ptr->next->name) == 0) {
            ptr->next = ptr->next->next;
        }
    }
}

void unset(shell_t *shell, char **av, int ac)
{
    if (ac < 2)
        my_errputstr("unset: Too few arguments.\n");
    for (int i = 1; av[i]; i++) {
        find_in_var(shell->var, av[i]);
    }
}
