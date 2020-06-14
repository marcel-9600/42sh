/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

command_t *check_null_command(command_t *command)
{
    for (int i = 0; command[i].sep != -1; i += 1) {
        if (!my_strcmp(command[i].cmd, "\0")) {
            my_errputstr("Invalid null command.\n");
            command[0].sep = -1;
        }
    }
    return (command);
}

int count_seperator(char *cmd)
{
    int counter = 0;

    for (int i = 0; cmd[i]; i += 1)
        if (i < my_strlen(cmd) - 1 && ((cmd[i] == '&' && cmd[i + 1] == '&')
        || (cmd[i] == '|' && cmd[i + 1] == '|')))
            counter += 1;
    return (counter);
}

int find_seperator(char const *cmd, int start)
{
    for (int i = start; cmd[i]; i += 1) {
        if (cmd[i] == '&' && cmd[i + 1] == '&')
            return (i);
        if (cmd[i] == '|' && cmd[i + 1] == '|')
            return (i);
    }
    return (-1);
}

command_t last_command(char *cmd, int prev)
{
    command_t command;
    command.sep = cmd[prev - 1];
    if ((command.cmd = malloc(sizeof(char) * (my_strlen(cmd) - prev)))
        == NULL) return (command);
    command.cmd = my_strnmcpy(command.cmd, cmd, prev,
        my_strlen(cmd));
    return (command);
}

command_t *get_sep_cmds(char *cmd)
{
    command_t *commands = NULL;
    int prev = 0;
    int sep_index = 0;
    int len = count_seperator(cmd);
    if ((commands = malloc(sizeof(command_t) * (len + 2))) == NULL)
        return (NULL);
    commands[len + 1].sep = -1;
    for (int j = 0; (sep_index = find_seperator(cmd, prev)) != -1; j++) {
        if (prev == 0) commands[j].sep = 0;
        else commands[j].sep = cmd[prev - 1];
        if ((commands[j].cmd = malloc(sizeof(char) * (sep_index - prev + 1)))
        == NULL) return (NULL);
        commands[j].cmd = my_strnmcpy(commands[j].cmd, cmd, prev, sep_index);
        prev = sep_index + 2;
    }
    if (len == 0) {
        commands[0].sep = 0;
        commands[0].cmd = my_strdup(cmd);
    } else
        commands[len] = last_command(cmd, prev);
    return (check_null_command(commands));
}