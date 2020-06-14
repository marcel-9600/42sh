/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void free_avs(char **tmp_av, char **av)
{
    for (int i = 0; tmp_av[i]; free(tmp_av[i]), i += 1);
    for (int i = 0; av[i]; free(av[i]), i += 1);
    free(tmp_av);
    free(av);
}

char **exec_aliases(var_t *head, char *cmd)
{
    var_t *og = head;
    char **av = my_str_to_special_array(cmd, " \t");
    char **tmp_av = NULL;
    char **new = NULL;
    int index = 0;
    for (; head != NULL; head = head->next) {
        if (!my_strcmp(head->name, av[0])) {
            tmp_av = my_str_to_special_array(head->value, " \t");
            if ((new = malloc(sizeof(char *) * (my_arraylen(av) + my_arraylen
                (tmp_av) + 1))) == NULL) return (NULL);
            for (int i = 0; i < my_arraylen(tmp_av); i += 1, index += 1)
                new[index] = my_strdup(tmp_av[i]);
            for (int i = 1; i < my_arraylen(av); i += 1, index += 1)
                new[index] = my_strdup(av[i]);
            head = og;
            free_avs(tmp_av, av);
            return (new);}
    }
    head = og;
    return (av);
}