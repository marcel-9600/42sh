/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int check_input(int argc, char **argv)
{
    if (argc > 3) {
        my_errputstr("setenv: Too many arguments.\n");
        return (84);
    }
    if ((argv[1][0] < 'A' || argv[1][0] > 'Z') && (argv[1][0] < 'a' ||
    argv[1][0] > 'z')) {
        my_errputstr("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    if (!my_str_isalpha(argv[1])) {
        my_errputstr("setenv: Variable name must contain alphanumeric "
"characters.\n");
        return (84);
    }
    return (0);
}

var_t *append(var_t *envp, char *name, char *value)
{
    var_t *tmp = envp;
    var_t *new = malloc(sizeof(var_t));
    for (; tmp->next != NULL; tmp = tmp->next);
    new->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    new->name = my_strcpy(new->name, name);
    if (value != NULL) {
        new->value = malloc(sizeof(char) * (my_strlen(value) + 1));
        new->value = my_strcpy(new->value, value);
    } else {
        new->value = "\0";
    }
    new->next = NULL;
    tmp->next = new;
    return (envp);
}

var_t *set_env(var_t *envp, int argc, char **input, int *ret)
{
    var_t *tmp = envp;

    if (check_input(argc, input) == 84) {
        *ret = 84;
        return (envp);
    }
    for (; my_strcmp(tmp->name, input[1]) != 0 && tmp->next != NULL;
    tmp = tmp->next);
    if (tmp->next == NULL && my_strcmp(tmp->name, input[1]) != 0)
        envp = append(envp, input[1], input[2]);
    else {
        free(tmp->value);
        tmp->value = "\0";
        if (argc == 3) {
            tmp->value = malloc(sizeof(char) * (my_strlen(input[2]) + 1));
            tmp->value = my_strcpy(tmp->value, input[2]);
        }
    }
    return (envp);
}