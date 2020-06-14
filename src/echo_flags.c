/*
** EPITECH PROJECT, 2019
** echo_flags.c
** File description:
** echo
*/

#include "../include/my.h"

int get_len_of_line(const char *output, int j)
{
    int count = 0;

    while (output[j] != '\n' && j >= 0) {
        j--;
        count++;
    }
    return count - 1;
}

char *flags_fvb(char *output, char c, int *j, int *i)
{
    if (c == 'f' || c == 'v') {
        int space = get_len_of_line(output, *j);
        output[*j] = '\n';
        ++*j;
        for (int k = 0; k < space; k++) {
            output[*j] = ' ';
            ++*j;
        }
        ++*i;
    }
    if (c == 'b') {
        output[*j - 1] = '\0';
        --*j;
        ++*i;
    }
    if (c == 'e') *i += 2;
    return output;
}

int is_valid_flag(char c)
{
    if (strchr("\\abcefnrtv0", c) == NULL)
        return 1;
    return 0;
}

char *flags_two(char *output, char c, int *j, int *i)
{
    if (c == 't') {
        output[*j] = '\t';
        output[*j + 1] = '\0';
        *j += 1;
        *i += 1;
    }
    output = flags_fvb(output, c, j, i);
    return output;

}

char *flags(char *output, char c, int *j, int *i)
{
    if (is_valid_flag(c) == 1) {
        output[*j] = '\\';
        output[*j + 1] = '\0';
        *j += 1;
        return output;
    }
    if (c == '\\') {
        output[*j] = '\\';
        output[*j + 1] = '\0';
        *j += 1;
        *i += 1;
    }
    if (c == 'n') {
        output[*j] = '\n';
        output[*j + 1] = '\0';
        *j += 1;
        *i += 1;
    }
    output = flags_two(output, c, j, i);
    return output;
}
