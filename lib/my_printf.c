/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** mains
*/

#include "../include/my.h"

params *create_arr(void)
{
    char flag_arr[13] = "scdbSxouX%ip\0";
    int (*function[13])(va_list, subs *) = {s_flag, c_flag, d_flag, b_flag, \
cap_s_flag, x_flag, o_flag, \
u_flag, cap_x_flag, percent_flag, \
d_flag, p_flag, '\0'};
    params *flag_functions = malloc(sizeof(params) * 13);

    for (int k = 0; k < 13; k += 1) {
        flag_functions[k].flag = flag_arr[k];
        flag_functions[k].fptr = function[k];
    }
    return (flag_functions);
}

int put_param(char *str, int i, va_list list)
{
    subs *mod = modifier(str, i);
    params *flag_functions = create_arr();

    i += mod->len + 1;
    for (int j = 0; flag_functions[j].flag != '\0'; j += 1) {
        if (str[i] == flag_functions[j].flag) {
            flag_functions[j].fptr(list, mod);
        }
    }
    free(mod);
    free(flag_functions);
    return (i);
}

int check_flag(char *str, int i, int tmp)
{
    int found = 0;
    char flag_arr[13] = "scdbSxouX%ip\0";

    for (int j = 0; j < 13; j += 1)
        if (flag_arr[j] == str[tmp])
            found = 1;
    if (!found)
        for (; i <= tmp; i += 1)
            my_putchar(str[i]);
    return (0);
}

int my_printf(char *str, ...)
{
    int counter = count_args(str);
    va_list list;
    int tmp = 0;

    if (!counter) {
        my_putstr(str);
    } else {
        va_start(list, str);
        for (int i = 0; str[i] != '\0'; i += 1) {
            if (str[i] == '%' && str[i + 1] != '\0') {
                tmp = put_param(str, i, list);
                check_flag(str, i, tmp);
                i = tmp;
            } else
                my_putchar(str[i]);
        }
    }
    return (0);
}
