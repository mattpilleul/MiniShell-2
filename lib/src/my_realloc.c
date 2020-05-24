/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

char *my_realloc(char *old, int size)
{
    char *new;
    int	i = -1;

    if ((new = malloc(sizeof(*new) * (my_strlen(old) + size))) == NULL)
        return (NULL);
    while (old[++i])
        new[i] = old[i];
    free(old);
    return (new);
}
