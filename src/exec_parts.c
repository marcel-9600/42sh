/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void if_path(exec_struct_t *my_struct, char **av)
{
    int fd = 0;
    if (my_struct->path != NULL) {
        if (my_struct->sep[0] == '>') output_redirect(my_struct->path,
            my_struct->sep);
        if (my_struct->sep[0] == '<' && my_struct->sep[1] != '<') {
            my_struct->ret = check_input_redirect(my_struct->path);
            if (my_struct->ret == 0) {
                fd = open(my_struct->path, O_RDONLY);
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
        }
        if (my_struct->sep[0] == '<' && my_struct->sep[1] == '<') {
            two_input_redirect(my_struct->path);
            fd = open(".ret_tmp", O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
        }
        rm_redirect(av);
    }
}

void after_exec(exec_struct_t *my_struct)
{
    if (my_struct->path != NULL) {
        free(my_struct->path);
        free(my_struct->sep);
    }
}

exec_struct_t init_struct(char **av)
{
    exec_struct_t my_struct;
    my_struct.ret = 0;
    my_struct.link;
    my_struct.child;
    my_struct.status = 0;
    my_struct.sep = get_from_av(av, 0);
    my_struct.path = get_from_av(av, 1);
    return (my_struct);
}

void do_exec(shell_t *shell, char **av, exec_struct_t *exe)
{
    exe->ret = execve(av[0], av, prep_env(shell->envp));
    if (errno == 13 || errno == 8)
        my_error_exit(strerror(errno), av[0]);
    if (exe->ret == -1)
        exe->ret = execve(find_executable(shell->paths, av[0]), av,
            prep_env(shell->envp));
    if (exe->ret == -1 && errno != 2 && errno != 14) my_error(strerror
    (errno), av[0]);
    after_exec(exe);
}
