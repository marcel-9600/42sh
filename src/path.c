/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

char **get_paths_env(var_t *envp, char **paths)
{
    var_t *tmp = envp;
    char **array = NULL;

    while (tmp != NULL && my_strcmp(tmp->name, "PATH"))
        tmp = tmp->next;
    if (tmp == NULL)
        return (paths);
    if (tmp->value != NULL)
        array = my_str_to_special_array(tmp->value, ":");
    return (array);
}

int search(DIR *dir, char *cmd)
{
    struct dirent *ent;
    while ((ent = readdir(dir)))
        if (!my_strcmp(ent->d_name, cmd))
            return (1);
    return (0);
}

char *find_executable(char **paths, char *cmd)
{
    char *ret = NULL;
    DIR *dir;
    int fd = 0;
    for (int i = 0; paths[i]; i += 1) {
        if ((dir = opendir(paths[i])) && search(dir, cmd)) {
            closedir(dir);
            ret = my_strdup(paths[i]);
            if (ret[my_strlen(ret) - 1] != '/')
                ret = my_malloc_strcat(ret, "/");
            ret = my_malloc_strcat(ret, cmd);
            if ((fd = open(ret, O_RDONLY)) > 0) {
                close(fd);
                return (ret);
            }
            free (ret);
        }
        closedir(dir);
    }
    return (NULL);
}