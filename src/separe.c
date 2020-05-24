/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int counter_str(char *string, char c, int k)
{
    int	i = 0;
    int	compt = 0;

    for (i = 0; string[i];){
        for (; string[i] && (string[i] == c || string[i] == k ||
        string[i] == '\t'); i++);
        compt += (string[i]) ? (1) : (0);
        i += (string[i]) ? (1) : (0);
    }
    return (compt);
}

char *add_tab(char *str, int compt)
{
    char *tab;
    int	i;
    int	size = compt;

    for (; str[size - 1] == ' ' || str[size - 1] == '\t'; size -= 1);
    if ((tab = malloc(sizeof(char) * size + 1)) == NULL)
        return (NULL);
    for (i = -1; str[++i] && i < size;)
        tab[i] = str[i];
    tab[i] = '\0';
    return (tab);
}

char *recup_str(char *str, int *i, char c, char k)
{
    int	size = 0;
    int	j = -1;
    int	length = 0;

    for (j = -1; str[++j] == c || str[j] == k;)
        length += 1;
    for (j = 0; str[j] && ((str[j] != c && str[j] != k));){
        size += 1;
        j += 1;
        (*i)++;
    }
    for (; length-- > 0;){
        (*i)++;
        size += 1;
    }
    (*i)--;
    return (add_tab(str, size));
}

char **separe_wordtab(char *str, char c)
{
    char **size = malloc((counter_str(str, c, '\0') + 1) * sizeof(*size));
    int	i = 0;
    int	z = -1;

    if (size == NULL)
        my_puterror("Error memory(2)");
    for (i = 0; str[i];){
        while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
            i += 1;
        size[++z] = (str[i]) ? recup_str(&str[i], &i, c, 12) : '\0';
        i += (str[i]) ? (1) : (0);
    }
    size[z + 1] = '\0';
    return (size);
}

char **manage_space_red(char **str)
{
    char **size;
    int i;
    int	z = -1;
    int	j = 0;

    if ((size = malloc(100 + counter_str(str[j], '>', '<') * sizeof(*size)))
    == NULL)
        my_puterror("Error memory(2)");
    for (j = 0; str[j]; j += 1){
        for (i = 0; str[j][i];){
            for (; str[j][i] && (str[j][i] == ' ' ||
            str[j][i] == '\t'); i += 1);
            size[++z] = (str[j][i]) ? recup_str(&(str[j][i]),
            &i, '>', '<') : '\0';
            i += (str[j][i]) ? (1) : (0);
        }
        size[z + 1] = '\0';
    }
    return (size);
}