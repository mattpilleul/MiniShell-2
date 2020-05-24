/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "lib.h"

int compt_str(char *str, char c)
{
    int	i = 0;
    int	count = 0;

    while (str[i]){
        while (str[i] && (str[i] == c || str[i] == '\t'))
            i++;
        if (str[i])
            count++;
        if (str[i] != '\0')
            i++;
    }
    return (count);
}

int	my_str_tab(const char *str, char c)
{
    int	i = -1;

    while (str[++i] != '\0' && str[i] != c && str[i] != '\t');
    return (i);
}

char **my_str_to_wordtab(char *str, char c)
{
    char **tab;
    int	i = 0;
    int	z = -1;
    int	j;

    if ((tab = malloc((compt_str(str, c) + 1) * sizeof(*tab))) == NULL)
        return (NULL);
    while (str[i]){
        j = 0;
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            ++i;
        if ((tab[++z] = malloc((my_str_tab(&str[i], c) + 1)
             * sizeof(**tab))) == NULL)
             return (NULL);
        while (str[i] && str[i] != c && str[i] != ' ' && str[i] != '\t')
            tab[z][j++] = str[i++];
        tab[z][j] = '\0';
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            ++i;
    }
    tab[z + 1] = '\0';
    return (tab);
}
