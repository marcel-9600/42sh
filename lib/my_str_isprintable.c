/*
** EPITECH PROJECT, 2019
** my_is_printable
** File description:
** fghjk
*/

int my_str_isprintable(char const *str)
{
    int bool = 1;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 31) {
            bool = 0;
            break;
        }
    }
    return (bool);
}
