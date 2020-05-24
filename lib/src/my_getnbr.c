/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

int my_getnbr(char *string)
{
    int value = 0;

    for (; *string ;) {
        if (*string >= '0' && *string <= '9') {
            value *= 10;
            value += *string - '0';
        } else
            return (-1);
        string++;
    }
    return (value);
}