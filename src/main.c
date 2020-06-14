/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void error(int ac, char **av)
{
    if (ac != 1 || av[0][0] == '\0')
        exit(84);
}

var_t *new_element(void)
{
    var_t *element = NULL;

    if ((element = malloc(sizeof(var_t))) == NULL)
        return (NULL);
    element->name = NULL;
    element->value = NULL;
    element->next = NULL;
    return (element);
}

var_t *put_var(var_t *envp, char *name, char *value)
{
    var_t *element = new_element();
    var_t *tmp = envp;

    element->name = name;
    if (value == NULL)
        element->value = "\0";
    else
        element->value = value;
    element->next = tmp;
    return (element);
}

var_t *get_enviroment(int ac, char **av, char **envp)
{
    char *tmp_name = NULL;
    char *tmp_value = NULL;
    var_t *environment = NULL;
    int j = 0;
    int len = 0;
    for (; envp[len]; len += 1);
    error(ac, av);
    for (int i = len - 1; envp[i]; i -= 1) {
        for (j = 0; envp[i][j] != '='; j += 1);
        if ((tmp_name = malloc(sizeof(char) * (j + 1))) == NULL)
            return (NULL);
        if ((tmp_value = malloc(sizeof(char) * (my_strlen(envp[i]) - j + 1)))
        == NULL)
            return (NULL);
        tmp_name = my_strncpy(tmp_name, envp[i], j);
        tmp_value = my_strmcpy(tmp_value, envp[i], j + 1);
        environment = put_var(environment, tmp_name, tmp_value);
    }
    return (environment);
}

int main(int ac, char **av, char **envp)
{
    shell_t shell;

    shell.envp = get_enviroment(ac, av, envp);
    shell.paths = get_paths_env(shell.envp, NULL);
    shell.alias = put_var(NULL, " ", "");
    shell.var = put_var(NULL, " ", "");
    shell.input = NULL;
    return (shell_main(&shell));
}