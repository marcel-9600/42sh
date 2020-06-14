/*
** EPITECH PROJECT, 2019
** echo.c
** File description:
** echo
*/

#include "../include/my.h"

char *check_octal(char *output, char *new, int *j, int *i)
{
    int oct_num = get_oct_num(new, *i);
    if (oct_num > 31 && oct_num < 127) {
        output[*j] = oct_num;
        ++*j;
        *i += 4;
    }
    return output;
}

int c_flag_echo(char c)
{
    if (c == 'c')
        return 1;
    return 0;
}

int echo_in_loop(const char *new, int *i, int *j, char *output)
{
    if (new[*i + 1] == '\\' && new[*i + 2] == 'c') return 1;
    output[*j] = new[*i + 1];
    output[*j + 1] = '\0';
    ++*j;
    ++*i;
    return 0;
}

char *get_output(char *output, char *new, int which_qoute)
{
    int j = 0;
    int qoutes = 0;

    for (int i = 0; i <= cut_from(new); i++) {
        if (new[i] == 34 || new[i] == 39) which_qoute = new[i], qoutes++, i++;
        if (new[i] == '\\' && qoutes % 2 != 0) {
            if (new[i + 1] == 'c') return output;
            if (new[i + 1] == '\\' && new[i + 2] == 'c') return output;
            if (c_flag_echo(new[i + 1]) == 1) return output;
            if (new[i + 1] == '0') check_octal(output, new, &j, &i);
            output = flags(output, new[i + 1], &j, &i);
        } else if (new[i] == '\\' && qoutes % 2 == 0) {
            if (echo_in_loop(new, &i, &j, output) == 1) return output;
        } else {
            output[j] = new[i];
            output[j + 1] = '\0';
            j++;
        }
    }
    if (echo_error(which_qoute, qoutes) == 1) return NULL; else return output;
}

void echo(char *line)
{
    char *new = NULL;
    int with_newline = 0;
    char *output = NULL;

    line += 5;
    line += cut_to(line);
    if (line[0] == ' ') line++;
    new = my_clean_string(line);
    if (new[0] == '-' && new[1] == 'n') {
        with_newline = 1;
        new += 3;
        new[my_strlen(new) - 1] = '\0';
    }
    output = malloc(sizeof(char) * 1000);
    output = get_output(output, new, 0);
    if (output != NULL) {
        my_printf("%s", output);
        if (with_newline != 1)
            my_printf("\n");
    }
}
