/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void clear_pipe_buffer(char *buffer)
{
    int len = my_strlen(buffer);

    for (int i = 0; buffer[i]; i += 1) {
        if (i > 0 && buffer[i] == '|' && !is_alnum(buffer[i - 1])
        && buffer[i - 1] != '|') {
            for (int j = i; j < len; j += 1)
                buffer[j - 1] = buffer[j];
            buffer[len - 1] = '\0';
        }
    }
}

int end_pipe_exec(int len, int pipefds[])
{
    int status = 0;
    int failure = 0;

    for (int j = 0; j < 2 * len; j += 1) close(pipefds[j]);
    for (int j = 0; j < len + 1; j += 1) {
        wait(&status);
        if (status)
            failure = status;
    }
    return (signal_handler(failure));
}

void pipe_prepare_link(int len, int i, int *pipefds)
{
    if (i > 0)
        dup2(pipefds[(i - 1) * 2], 0);
    if (i + 1 < len + 1)
        dup2(pipefds[i * 2 + 1], 1);
    for (int j = 0; j < 2 * len; j += 1)
        close(pipefds[j]);
}

void pipe_execve(exec_struct_t *exe, char **cmds, shell_t *shell)
{
    if (!exe->ret) {
        exe->ret = execve(cmds[0], cmds, prep_env(shell->envp));
        if (errno == 13 || errno == 8)
            my_error_exit(strerror(errno), cmds[0]);
        if (exe->ret == -1)
            exe->ret = execve(find_executable(shell->paths, cmds[0]), cmds,
            prep_env(shell->envp));
        if (exe->ret == -1 && errno != 2 && errno != 14)
            my_error_exit(strerror(errno), cmds[0]);
        after_exec(exe);
    } else exit(84);
}

int pipe_exec(shell_t *shell, char **pipes)
{
    int pipefds[2 * (my_arraylen(pipes) - 1)];
    pid_t pid;
    char **cmds = NULL;
    for (int i = 0; i < my_arraylen(pipes) - 1; i += 1)
        if (pipe(pipefds + i * 2) < 0) return (84);
    for (int i = 0; pipes[i]; i += 1) {
        cmds = exec_aliases(shell->alias, pipes[i]);
        pid = fork();
        if (pid == 0) {
            pipe_prepare_link(my_arraylen(pipes) - 1, i, pipefds);
            if (shell_loop_builtins(shell, pipes[i]) == 1) {
                exec_struct_t exe = init_struct(cmds);
                if_path(&exe, cmds);
                pipe_execve(&exe, cmds, shell);
                exe.child == 0 ? my_error("Command not found", cmds[0]) : 0;
                exe.child == 0 ? exit(3) : 0;
            } else exit (1);
        } else if (pid < 0)
            my_error_exit(strerror(errno), cmds[0]);
    }
    return (end_pipe_exec(my_arraylen(pipes) - 1, pipefds));
}
