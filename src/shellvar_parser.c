/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int is_alphanumeric(char c)
{
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')
        && (c < '0' || c > '9') && c != '_')
        return (0);
    return (1);
}

char *find_value(char *name, var_t *var, var_t *env)
{
    for (; var; var = var->next) {
        if (!my_strcmp(name, var->name))
            return (var->value);
    }
    for (; env; env = env->next) {
        if (!my_strcmp(name, env->name))
            return (env->value);
    }
    return (NULL);
}

char *replace_var(char *input, char *value, int m, int n)
{
    char *pre = NULL;
    char *post = NULL;
    char *ret = NULL;

    if ((pre = malloc(sizeof(char) * (m + 1))) == NULL) return (NULL);
    if (n > 0 && (post = malloc(sizeof(char) * (my_strlen(input - n + 1)))) ==
    NULL) return (NULL);
    if ((ret = malloc(sizeof(char) * (my_strlen(input) - (n - m) + my_strlen
        (value) + 1))) == NULL) return (NULL);
    pre = my_strncpy(pre, input, m);
    post = my_strmcpy(post, input, n);
    ret = my_strcat(ret, pre);
    ret = my_strcat(ret, value);
    ret = my_strcat(ret, post);
    free(pre);
    free(post);
    return (ret);
}

char *parse_input(char *input, var_t *var, var_t *env)
{
    int n = 0;
    int m = 0;
    char *value = NULL;
    char *name = NULL;
    for (; input[m]; m += 1) {
        if ((m == 0 && input[m] == '$') || ( m > 0  && input[m] == '$' &&
        input[m - 1] != '\\')) {
            for (n = m + 1; input[n] && is_alphanumeric(input[n]); n += 1);
            if ((name = malloc(sizeof(char) * (n - m))) == NULL)
                return (NULL);
            name = my_strnmcpy(name, input, m + 1, n);
            if ((value = find_value(name, var, env)) != NULL)
                input = replace_var(input, value, m, n);
            else {
                my_error("Undefined variable", name);return (NULL);
            }
            m = 0;
        }
    }
    return (input);
}
