/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

int	my_putstr(char *str)
{
    int	i = 0;

    while (str[i])
        my_putchar(str[i++]);
    return (0);
}
