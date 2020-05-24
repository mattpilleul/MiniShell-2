/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

char my_strncmp(char *s1, char *s2, int len)
{
    int	i = -1;

    while ((s1[i] != '\0') && (i < len)){
        if (s1[i] != s2[i])
            return (0);
        i += 1;
    }
    return (1);
}
