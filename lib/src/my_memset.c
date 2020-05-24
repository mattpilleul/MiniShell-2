/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

void *my_memset(void *s, int c, int n)
{
    int i = -1;

    while (++i < n)
        ((char *)s)[i] = c;
    return (s);
}
