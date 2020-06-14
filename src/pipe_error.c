/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int count_pipes(char *cmd)
{
    int pipe = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '|' && cmd[i + 1] != '|')
            pipe++;
        if (cmd[i] == '|' && cmd[i + 1] == '|')
            continue;
    }
    return pipe;
}

int count_cmds(char *cmd)
{
    int count = 0;
    int letter = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != '|')
            letter = 1;
        if (letter == 1 && cmd[i] == '|') {
            count++;
            letter = 0;
        }
    }
    if (letter == 1)
        ++count;
    return count;
}

int check_last(char *cmd, int i)
{
    int count = 0;

    while (cmd[i] != '|' && i >= 0) {
        if (cmd[i] != ' ' && cmd[i] != '\t')
            count++;
        i--;
    }
    if (count == 0)
        return 1;
    return 0;
}

int check_fl_cmd(char *cmd)
{
    int i = 0;
    int count = 0;

    if (cmd[0] != '|') {
        while (cmd[i] != '|' && cmd[i]) {
            if (cmd[i] != ' ' && cmd[i] != '\t') count++;
            i++;
        }
        if (count == 0) return 1;
    }
    if (cmd[my_strlen(cmd) - 1] == ' ' || cmd[my_strlen(cmd) - 1] == '\t')
        if (check_last(cmd, my_strlen(cmd) - 1) == 1) return 1;
    return 0;
}
