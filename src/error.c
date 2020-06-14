/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int my_errputstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
    return (0);
}

void my_error_exit(char *message, char *argument)
{
    my_errputstr(argument);
    my_errputstr(": ");
    my_errputstr(message);
    if (my_strcmp(message, "Exec format error"))
        my_errputstr(".\n");
    else
        my_errputstr(". Wrong Architecture.\n");
    exit(84);
}

void my_error(char *message, char *argument)
{
    my_errputstr(argument);
    my_errputstr(": ");
    my_errputstr(message);
    my_errputstr(".\n");
}