/*
** EPITECH PROJECT, 2019
** simple af
** File description:
** putchar
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
