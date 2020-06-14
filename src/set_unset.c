/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int check_set_input(int i, char **av)
{
    int c = 0;

    if ((av[i][0] < 'A' || av[i][0] > 'Z') && (av[i][0] < 'a' ||
    av[i][0] > 'z')) {
        my_errputstr("set: Variable name must begin with a letter.\n");
        return (84);
    }
    for (int j = 0; av[i][j]; j++) {
        if ((av[i][j] >= 'a' && av[i][j] <= 'z') || av[i][j] == '=') c++;
        if (av[i][j] >= 'A' && av[i][j] <= 'Z') c++;
        if (av[i][j] >= '0' && av[i][j] <= '9') c++;
        if (c == 0) {
            my_errputstr("set: Variable name must contain alphanumeric "
"characters.\n");
            return 84;
        } else
            c = 0;
    }
    return 0;
}

int check_double_set(var_t *new, var_t *ptr)
{
    if (strcmp(new->name, ptr->next->name) == 0) {
        ptr->next->value = new->value;
        return 1;
    }
    return 0;
}

void put_in(var_t *var, char *arg, char *command)
{
    var_t *ptr = NULL;
    var_t *new = NULL;

    if ((new = malloc(sizeof(var_t))) == NULL) return;
    new->name = arg;
    if (command != NULL) new->value = command;
    else new->value = "\0";
        new->next = NULL;

    if (set_first_alias(var, new) == 1) return;
    ptr = var;
    while (ptr->next) {
        if (strcmp(new->name, ptr->next->name) < 0) {
            new->next = ptr->next;
            ptr->next = new;
            return;
        }
        if (check_double_set(new, ptr) == 1) return;
        ptr = ptr->next;
    }
    ptr->next = new;
}

void show_set(var_t *var)
{
    var_t *tmp = NULL;
    tmp = var->next;
    for (; tmp; tmp = tmp->next) {
        my_printf("%s\t%s\n", tmp->name, tmp->value);
    }
}

int set(shell_t *shell, char **av, int ac)
{
    int n = 0;
    char *arg = NULL;
    char *cmd = NULL;

    for (int i = 1; av[i]; i++) {
        if (check_set_input(i, av) == 84) return 84;
        if ((n = count_to(av[i], '=')) == -1) {
            arg = my_strdup(av[i]);
            put_in(shell->var, arg, NULL);
            continue;
        }
        if ((arg = malloc(sizeof(char) * n + 1)) == NULL) return 84;
        arg = my_strncpy(arg, av[i], n);
        av[i] += n + 1;
        cmd = my_strdup(av[i]);
        put_in(shell->var, arg, cmd);
    }
    return 0;
}
