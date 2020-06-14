/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include//my.h"

char *strcat_command(char **av)
{
    char *ret = my_strdup(av[2]);

    if (av[2] != NULL) {
        for (int i = 3; av[i]; i += 1) {
            ret = my_malloc_strcat(ret, " ");
            ret = my_malloc_strcat(ret, av[i]);
        }
    }
    return (ret);
}

int set_first_alias(var_t *head, var_t *new)
{
    if (head->name == NULL && head->next == NULL) {
        head->name = new->name;
        head->value = new->value;
        head->next = NULL;
        return 1;
    }
    return 0;
}

int double_alias(var_t *new, var_t *ptr)
{
    if (strcmp(new->name, ptr->next->name) == 0) {
        free(ptr->next->value);
        ptr->next->value = new->value;
        return 1;
    }
    return 0;
}

void set_alias(var_t *head, char **av)
{
    var_t *ptr = NULL;
    var_t *new = NULL;

    if ((new = malloc(sizeof(var_t))) == NULL) return;
    new->name = my_strdup(av[1]);
    new->value = strcat_command(av);
    new->next = NULL;

    if (set_first_alias(head, new) == 1) return;
    ptr = head;
    while (ptr->next) {
        if (strcmp(new->name, ptr->next->name) < 0) {
            new->next = ptr->next;
            ptr->next = new;
            return;
        }
        if (double_alias(new, ptr) == 1) return;
        ptr = ptr->next;
    }
    ptr->next = new;
}

void my_alias(var_t *alias, int ac, char **av)
{
    var_t *og = alias;

    if (ac == 1) {
        for (og = og->next; og != NULL; og = og->next)
            my_printf("%s\t(%s)\n", og->name, og->value);
    }
    else if (ac == 2) {
        for (; og != NULL && my_strcmp(og->name, av[1]); og = og->next);
        if (og != NULL)
            my_printf("%s\t(%s)\n", og->name, og->value);
    } else
        set_alias(alias, av);
}
