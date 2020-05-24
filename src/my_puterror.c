/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

void my_puterror(char *str)
{
    my_putstr_err(str);
    exit(1);
}

char error_cd(char *str, char *cd)
{
    my_putstr_err(cd);
    my_putstr_err(":");
    my_putstr_err(" ");
    my_putstr_err(str);
    my_putstr_err("\n");
    return (0);
}

char error_execve(char *error, char **cmd)
{
    my_putstr(cmd[0]);
    if (my_strlen(error) == 0)
        my_putstr(": Command not found.");
    else
        my_putstr(": Permission denied.");
    my_putstr("\n");
    return (0);
}
