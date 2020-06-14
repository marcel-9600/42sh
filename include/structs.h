/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef PSU_MINISHELL1_2019_STRUCTS_H
#define PSU_MINISHELL1_2019_STRUCTS_H

typedef struct var_s
{
    char *name;
    char *value;
    struct var_s *next;
} var_t;

typedef struct exec_struct_s
{
    int ret;
    int link[2];
    pid_t child;
    int status;
    char *sep;
    char *path;
} exec_struct_t;

typedef struct command_s
{
    char sep;
    char *cmd;
} command_t;

typedef struct shell_s
{
    var_t *envp;
    char **paths;
    var_t *alias;
    var_t *var;
    char *input;
} shell_t;

#endif //PSU_MINISHELL1_2019_STRUCTS_H
