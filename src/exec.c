/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int simple_exec(shell_t *shell, char *arg)
{
    char **argv = NULL;
    int ret = 1;

    argv = exec_aliases(shell->alias, arg);
    if (my_arraylen(argv) > 0 && (ret = shell_loop_builtins(shell, arg)) == 1) {
        if ((ret = my_exec(shell, argv)) == 3) {
            my_error("Command not found", argv[0]);
            return (1);
        } else
            return (ret);
    } else
        return (ret);
}

char **prep_env(var_t *envp)
{
    int len = 0;
    char **new;
    var_t *tmp = envp;

    for (var_t *tmp = envp; tmp->next; tmp = tmp->next, len += 1);
    new = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i < len; i += 1, tmp = tmp->next) {
        new[i] = malloc(sizeof(char) * (my_strlen(tmp->name) +
            my_strlen(tmp->value) + 2));
        new[i] = my_malloc_strcat(tmp->name, my_malloc_strcat("=",
            tmp->value));
    }
    new[len] = NULL;
    return (new);
}

int signal_handler(int status)
{
    if (status == 256 || status == 13)
        return (1);
    if (WTERMSIG(status) == SIGSEGV)
        my_putstr("Segmentation fault");
    else if (WTERMSIG(status) == SIGFPE)
        my_putstr("Floating exception");
    if (WCOREDUMP(status)) {
        my_putstr(" (core dumped)\n");
        return (1);
    }
    else if (WIFSIGNALED(status)) {
        my_putchar('\n');
        return (1);
    }
    return (WEXITSTATUS(status));
}

int my_exec(shell_t *shell, char **av)
{
    exec_struct_t exe = init_struct(av);
    if ((exe.child = fork()) == 0) {
        if_path(&exe, av);
        if (!exe.ret) {
            do_exec(shell, av, &exe);
        } else exit(84);
        exe.child == 0 ? exit(3) : 0;
    }
    waitpid(0, &exe.status, 0);
    return (signal_handler(exe.status));
}