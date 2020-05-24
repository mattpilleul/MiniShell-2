/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

int	my_strlen(char *str)
{
    int	i = 0;

    while (*str && str[i++]);
    return (i);
}
