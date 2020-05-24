/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
    int	i = 0;

    if (str == NULL)
        return (0);
    for (i = 0; str[i] && str[i] != '\0'; i++);
    return (i);
}

char my_strcmp(char *s1, char *s2, int len)
{
    int	i = -1;

    for (i = -1; s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i];);
    if (len == 1)
        return (s1[i] == '=' && s2[i] == '\0');
    return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

char *my_strdup(char *str)
{
    int	i;
    char *str2;

    if (str == NULL)
        return (NULL);
    if ((str2 = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
        my_putstr("Error memory(1)");
    for (i = -1; str[++i] != '\0';)
        str2[i] = str[i];
    str2[i] = '\0';
    return (str2);
}

char *my_strcat(char *path, char *cmd, int cond)
{
    char *size;
    int	i;
    int	j;

    if (path == NULL || cmd == NULL)
        return (NULL);
    if ((size = malloc(sizeof(char) * (my_strlen(path) +
        my_strlen(cmd) + 2))) == NULL)
        my_puterror("Error memory");
    for (i = -1; path[++i] != '\0';)
        size[i] = path[i];
    if (cond == 1)
        size[i++] = '/';
    if (cond == 2)
        size[i++] = '=';
    for (j = 0; cmd[j] != '\0';)
        size[i++] = cmd[j++];
    size[i] = '\0';
    return (size);
}