/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	my_str_isalpha(char *str)
{
    int	i = 0;

    while (str && str[i]){
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (84);
        i++;
    }
    return (0);
}