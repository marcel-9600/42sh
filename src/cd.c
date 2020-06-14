/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

char *get_value(var_t *envp, char *str)
{
    char *new;

    for (; my_strcmp(envp->name, str) != 0 && envp->next; envp = envp->next);
    if (envp->next == NULL && my_strcmp(envp->name, str) != 0)
        return (NULL);
    new = malloc(sizeof(char) * (my_strlen(envp->value) + 1));
    new = my_strcpy(new, envp->value);
    return (new);
}

var_t *update_value(var_t *envp, char *name, int *ret)
{
    var_t *tm = envp;
    char value[4096];

    if (getcwd(value, 4096) == NULL) {
        *ret = 84;
        my_errputstr(strerror(errno));
        my_errputstr("\n");
        return (envp);
    }
    for (; tm->next && my_strcmp(name, tm->name); tm = tm->next);
    if (tm->next == NULL && my_strcmp(name, tm->name) != 0 && !my_strcmp
    (name, "OLDPWD"))
        return (envp);
    if (!tm->next && my_strcmp(name, tm->name) != 0 && !my_strcmp(name, "PWD"))
        return (append(envp, "PWD", value));
    free(tm->value);
    tm->value = malloc(sizeof(char) * (my_strlen(value) + 1));
    tm->value = my_strcpy(tm->value, value);
    tm->value[my_strlen(value)] = '\0';
    return (envp);
}

var_t *reverse_cd(var_t *envp, int *ret)
{
    char *dest;

    if ((dest = get_value(envp, "OLDPWD")) == NULL)
        return (envp);
    envp = update_value(envp, "OLDPWD", ret);
    if (chdir(dest) == -1) {
        *ret = 84;
        my_error(strerror(errno), dest);
        return (envp);
    }
    envp = update_value(envp, "PWD", ret);
    return (envp);
}

var_t *change_dir(var_t *envp, char *dest, int *ret)
{
    envp = update_value(envp, "OLDPWD", ret);
    if (chdir(dest) == -1) {
        *ret = 84;
        my_error(strerror(errno), dest);
        return (envp);
    }
    free(dest);
    envp = update_value(envp, "PWD", ret);
    return (envp);
}

var_t *my_cd(var_t *envp, char **argv, int *ret)
{
    char *dest;

    if (argv[2]) {
        *ret = 84;
        my_errputstr("cd: Too many arguments.\n");
        return (envp);
    }
    if (argv[1] == NULL || !my_strcmp(argv[1], "~")) {
        if ((dest = get_value(envp, "HOME")) == NULL)
            return (envp);
    }
    else if (!my_strcmp(argv[1], "-")) {
        if ((dest = get_value(envp, "OLDPWD")) == NULL)
            return (reverse_cd(envp, ret));
    } else {
        dest = malloc(sizeof(char) * (my_strlen(argv[1]) + 1));
        dest = my_strcpy(dest, argv[1]);
    }
    return (change_dir(envp, dest, ret));
}