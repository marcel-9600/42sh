/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void rm_redirect(char **argv)
{
    int len = my_arraylen(argv);

    for (int i = 0; argv[i]; i += 1) {
        if (argv[i][0] == '<' || argv[i][0] == '>') {
            free(argv[i]);
            argv[i] = NULL;
            free(argv[i + 1]);
            argv[i + 1] = NULL;
            if (len >= i + 2) {
                for (int j = i + 2; j < len; j += 1) {
                    free(argv[j - 2]);
                    argv[j - 2] = NULL;
                    argv[j - 2] = my_strdup(argv[j]);
                    free(argv[j]);
                    argv[j] = NULL;
                }
            }
            break;
        }
    }
}

char *get_from_av(char **argv, int path)
{
    for (int i = 0; argv[i]; i += 1) {
        if (argv[i][0] == '<' || argv[i][0] == '>') {
            if (path)
                return (my_strdup(argv[i + 1]));
            return (my_strdup(argv[i]));
        }
    }
    return (NULL);
}

int output_redirect(char *path, char const *sep)
{
    int fd = 0;

    if (sep[0] == '>' && sep[1] != '>')
        fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    else if (sep[0] == '>' && sep[1] == '>')
        fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0664);
    dup2(fd, STDOUT_FILENO);
    return (0);
}

int check_input_redirect(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        my_error(strerror(errno), path);
        close(fd);
        return (-1);
    }
    return (0);
}

int two_input_redirect(char *path)
{
    char *buffer = "\0";
    size_t buffsize;
    int len = 0;
    char *line = NULL;
    int fd = 0;

    while (1) {
        my_putstr("> ");
        if ((len = getline(&line, &buffsize, stdin)) == -1)
            break;
        line[len - 1] = '\0';
        if (my_strcmp(path, line)) {
            line[len - 1] = '\n';
            buffer = my_malloc_strcat(buffer, line);
        } else
            break;
    }
    fd = open(".ret_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0664);
    write(fd, buffer, my_strlen(buffer));
    close(fd);
    return (fd);
}