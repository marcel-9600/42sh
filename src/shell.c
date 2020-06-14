/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void show_env(var_t *element, int argc, char **argv, int *ret)
{
    if (argc == 1) {
        my_printf("%s=%s\n", element->name, element->value);
        if (element->next == NULL)
            return;
        show_env(element->next, argc, argv, ret);
    } else {
        *ret = 84;
        my_errputstr("env: '");
        my_errputstr(argv[1]);
        my_errputstr("': No such file or directory\n");
    }
}

void handle_signal(int sig)
{
    my_putstr("\n");
}

void my_exit(int argc, char **argv, int *error)
{
    int bool = 0;
    int ret = 0;
    if (argc == 1) {
        my_putstr("exit\n");
        exit(ret);
    }
    for (int i = 0; argv[1][i]; i += 1)
        if (argv[1][i] >= '0' && argv[1][i] <= '9')
            bool = 1;
    if (argc > 2 || !my_str_isnum(argv[1])) {
        *error = 84;
        if (!my_str_isnum(argv[1]) && bool)
            my_errputstr("exit: Badly formed number.\n");
        else
            my_errputstr("exit: Expression Syntax.\n");
        return;
    }
    ret = my_getnbr(argv[1]);
    if (ret < 0) ret += 255;
    my_putstr("exit\n");
    exit(ret);
}

int shell_main(shell_t *shell)
{
    int len = 0;
    size_t buffsize;
    char *buffer = NULL;
    char *oldpwd[] = {"setenv", "OLDPWD", get_value(shell->envp, "PWD")};
    int ret = 0;

    shell->envp = set_env(shell->envp, 3, oldpwd, &ret);
    signal(SIGINT, handle_signal);
    while (1) {
        prompt(shell->envp);
        len = getline(&buffer, &buffsize, stdin);
        if (len == -1)
            return (0);
        buffer[len - 1] = '\0';
        clear_pipe_buffer(buffer);
        shell->input = my_strdup(buffer);
        exec_cmds(shell);
        buffer = NULL;
        shell->paths = get_paths_env(shell->envp, shell->paths);
    }
}