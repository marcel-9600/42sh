/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int my_which(char **paths, int ac, char **av)
{
    char *path = NULL;
    int ret = 0;
    if (ac < 2) {
        my_errputstr("which: Too few arguments.\n");
        return (84);
    }
    for (int i = 1; i < ac; i += 1) {
        if (!my_strcmp(av[i], "exit") || !my_strcmp(av[i], "env") ||
        !my_strcmp(av[i], "cd") || !my_strcmp(av[i], "setenv") ||
        !my_strcmp(av[i], "unsetenv") || !my_strcmp(av[i], "echo") ||
        !my_strcmp(av[i], "which") || !my_strcmp(av[i], "where"))
            my_printf("%s: shell built-in command.\n", av[i]);
        else if ((path = find_executable(paths, av[i])) != NULL)
                my_printf("%s\n", path);
        else {
            ret = 2;
            my_printf("%s: Command not found.\n", av[i]);
        }
    }
    free(path);return (ret);
}

char *set_executable(char *path, char *cmd)
{
    char *ret = NULL;

    ret = my_strdup(path);
    if (ret[my_strlen(ret) - 1] != '/')
        ret = my_malloc_strcat(ret, "/");
    ret = my_malloc_strcat(ret, cmd);
    return (ret);
}

int count_executables(char **paths, char *cmd)
{
    int count = 0;
    DIR *dir;
    int fd = 0;
    char *ret = NULL;
    for (int i = 0; paths[i]; i += 1) {
        if ((dir = opendir(paths[i])) && search(dir, cmd)) {
            closedir(dir);
            ret = set_executable(paths[i], cmd);
            if ((fd = open(ret, O_RDONLY)) > 0) {
                close(fd);
                count += 1;
            }
            free(ret);
        }
    }
    return (count);
}

char **find_all_executables(char **paths, char *cmd)
{
    char **ret = NULL;
    DIR *dir;
    int fd = 0;
    int j = 0;
    int len = count_executables(paths, cmd);
    if ((ret = malloc(sizeof(char *) * (len + 1))) == NULL) return (NULL);
    ret[len] = NULL;
    if (!len) return (NULL);
    for (int i = 0; paths[i]; i += 1) {
        if ((dir = opendir(paths[i])) && search(dir, cmd)) {
            closedir(dir);
            ret[j] = set_executable(paths[i], cmd);
            if ((fd = open(ret[j], O_RDONLY)) > 0) {
                close(fd);
            } else free(ret[j]);
            j += 1;
        }
    }
    return (ret);
}

int my_where(char **paths, int ac, char **av)
{
    char **path = NULL;
    int ret = 0;
    if (ac < 2) {
        my_errputstr("which: Too few arguments.\n");
        return (84);
    }
    for (int i = 1; i < ac; i += 1) {
        if (!my_strcmp(av[i], "exit") || !my_strcmp(av[i], "env") ||
            !my_strcmp(av[i], "cd") || !my_strcmp(av[i], "setenv") ||
            !my_strcmp(av[i], "unsetenv") || !my_strcmp(av[i], "echo") ||
            !my_strcmp(av[i], "which") || !my_strcmp(av[i], "where"))
            my_printf("%s is a shell built-in\n", av[i]);
        if ((path = find_all_executables(paths, av[i])) != NULL)
            for (int j = 0; path[j]; my_printf("%s\n", path[j]), j += 1);
        else
            ret = 2;
    }
    free(path);
    return (ret);
}
