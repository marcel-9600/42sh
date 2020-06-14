/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int count_builtins(char **cmds)
{
    int counter = 0;
    char **tmp = NULL;

    for (int i = 0; cmds[i]; i += 1) {
        tmp = my_str_to_special_array(cmds[i], " \t");
        if (!my_strcmp(tmp[0], "exit") || !my_strcmp(tmp[0], "env") ||
        !my_strcmp(tmp[0], "cd") || !my_strcmp(tmp[0], "setenv") ||
        !my_strcmp(tmp[0], "unsetenv") || !my_strcmp(tmp[0], "which") ||
        !my_strcmp(tmp[0], "where") || !my_strcmp(tmp[0], "alias") ||
        !my_strcmp(tmp[0], "set") || !my_strcmp(tmp[0], "unset") ||
        !my_strcmp(tmp[0], "echo") || !my_strcmp(tmp[0], "repeat"))
            counter += 1;
        for (int j = 0; tmp[j]; j += 1)
            free(tmp[j]);
        free(tmp);
        tmp = NULL;
    }
    return (counter);
}