/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int shell_loop_builtins3(shell_t *shell, int ac, char **av)
{
    int ret = 0;
    if (my_strcmp(av[0], "exit") == 0) {
        my_exit(my_arraylen(av), av, &ret);
        return (ret);}
    if (my_strcmp(av[0], "cd") == 0) {
        my_cd(shell->envp, av, &ret);
        return (ret);
    }
    if (my_strcmp(av[0], "set") == 0) {
        if (ac == 1) show_set(shell->var);
        else set(shell, av, ac);
        return ret;
    }
    if (my_strcmp(av[0], "unset") == 0) {
        unset(shell, av, ac);
        return ret;
    }
    for (int i = 0; av[i]; free(av[i]), i += 1);
    free(av);
    return (1);
}

int shell_loop_builtins2(shell_t *shell, int ac, char **av)
{
    int ret = 0;

    if (!my_strcmp(av[0], "env") || (!my_strcmp(av[0], "setenv") && ac == 1)) {
        show_env(shell->envp, ac, av, &ret);
        return (ret);
    }
    if (my_strcmp(av[0], "setenv") == 0) {
        shell->envp = set_env(shell->envp, ac, av, &ret);
        return (ret);
    }
    if (my_strcmp(av[0], "unsetenv") == 0) {
        shell->envp = unset_env(shell->envp, ac, av, &ret);
        return (ret);
    }
    if (!my_strcmp(av[0], "repeat"))
        return (my_repeat(shell, av));
    if (!my_strcmp(av[0], "true")) return (0);
    if (!my_strcmp(av[0], "false")) return (2);
    return (shell_loop_builtins3(shell, ac, av));
}

int shell_loop_builtins(shell_t *shell, char *cmd)
{
    int ret = 0;
    char **av = exec_aliases(shell->alias, cmd);

    if (my_strcmp(av[0], "which") == 0) {
        ret = my_which(shell->paths, my_arraylen(av), av);
        return (ret);
    }
    if (my_strcmp(av[0], "where") == 0) {
        ret = my_where(shell->paths, my_arraylen(av), av);
        return (ret);
    }
    if (my_strcmp(av[0], "alias") == 0) {
        my_alias(shell->alias, my_arraylen(av), av);
        return (ret);
    }
    if (my_strcmp(av[0], "echo") == 0 && shell->paths == NULL) {
        echo(cmd);
        return ret;
    }
    return (shell_loop_builtins2(shell, my_arraylen(av), av));
}