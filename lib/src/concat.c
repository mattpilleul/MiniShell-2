/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

char *concat(char *str, char *str2)
{
    char *tampon;
    int	i;
    int	length;
    int	y;

    if ((tampon = malloc(sizeof(char) * (my_strlen(str) +
    my_strlen(str2)))) == NULL)
        return (NULL);
    length = my_strlen(str);
    for (i = -1; ++i < length;)
        tampon[i] = str[i];
    length = my_strlen(str2);
    i -= 1;
    for (y = -1; ++y < length;)
        tampon[i++] = str2[y];
    tampon[i] = '\0';
    return (tampon);
}
