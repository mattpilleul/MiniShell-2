/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

void my_putstr_err(char *str)
{
    if (write(2, str, my_strlen(str)) == -1)
        exit (1);
}
