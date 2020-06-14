/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int repeat_error(char **cmd)
{
    if (my_arraylen(cmd) < 3) {
        my_errputstr("repeat: Too few arguments.\n");
        return (1);
    }
    if (!my_str_isnum(cmd[1])) {
        my_errputstr("repeat: Badly formed number.\n");
        return (1);
    }
    return (0);
}

int my_repeat(shell_t *shell, char **cmd)
{
    if (repeat_error(cmd))
        return (2);
    else {
        shell->input = strcat_command(cmd);
        for (int i = 0; i < my_getnbr(cmd[1]); i += 1)
            exec_cmds(shell);
    }
    return (0);
}