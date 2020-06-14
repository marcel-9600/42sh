/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int check_cmd(char *cmd)
{
    int all_pipes = 0;
    int pipes = count_pipes(cmd);
    int cmd_count = count_cmds(cmd);

    if (check_fl_cmd(cmd) == 1)
        return 1;
    for (int i = 0; cmd[i]; i++)
        if (cmd[i] == '|') all_pipes++;
    if (pipes + 1 == cmd_count && all_pipes <= 2 * pipes)
        return 0;
    return 1;
}

int check_pipes(char **pipes)
{
    int count = 0;

    for (int i = 0; pipes[i]; i++) {
        for (int j = 0; pipes[i][j]; j++) {
            if (pipes[i][j] == ' ' || pipes[i][j] == '\t') count++;
        }
        if (count == my_strlen(pipes[i]))
            return 1;
        count = 0;
    }
    return 0;
}

int pipe_error(char *cmds, char **pipes)
{
    if (check_cmd(cmds) == 1 || check_pipes(pipes) == 1) {
        my_errputstr("Invalid null command.\n");
        return 1;
    }
    return 0;
}

void inner_exec_cmds(shell_t *shell, char *cmds)
{
    command_t *commands = get_sep_cmds(cmds);
    char **pipes = NULL;
    int ret = 0;
    for (int j = 0; commands[j].sep != -1; j += 1) {
        if ((commands[j].cmd = parse_input(commands[j].cmd, shell->var,
            shell->envp)) != NULL && (commands[j].sep == 0 || (commands[j]
            .sep == '&' && !ret) || (commands[j].sep == '|' && ret))) {
            pipes = my_str_to_special_array(commands[j].cmd, "|");
            if (commands[j].cmd[0] == '|' || commands[j].cmd[my_strlen
            (commands[j].cmd) - 1] == '|') {
                my_errputstr("Invalid null command.\n");
                continue;
            }
            if (my_arraylen(pipes) == 1) {
                ret = simple_exec(shell, pipes[0]);
                continue;
            }
            if (pipe_error(commands[j].cmd, pipes) == 1) continue;
            ret = pipe_exec(shell, pipes);}
    }
}

void exec_cmds(shell_t *shell)
{
    char **cmds = NULL;

    cmds = my_str_to_special_array(shell->input, ";");
    for (int i = 0; cmds[i]; i += 1) {
        inner_exec_cmds(shell, cmds[i]);
    }
}
