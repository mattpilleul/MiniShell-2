/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *use_pers_path(char *env_path)
{
    if (env_path == NULL)
        return ("/bin:/sbin:/usr/bin:/usr/sbin");
    return (env_path);
}

int	my_builtin(cmd_t *cmd, env_t *env)
{
    char (*my_redirection[5])(char **, env_t *);
    char **my_built = malloc(sizeof(char *) * 5);
    int	i;

    if (my_built == NULL)
        my_puterror("Error memory(5)");
    my_built[0] = "exit";
    my_built[1] = "cd";
    my_built[2] = "env";
    my_built[3] = "unsetenv";
    my_built[4] = "setenv";
    my_redirection[0] = builtin_exit;
    my_redirection[1] = builtin_cd;
    my_redirection[2] = builtin_env;
    my_redirection[3] = builtin_unsetenv;
    my_redirection[4] = builtin_setenv;
    for (i = -1; ++i < 5 && !my_strcmp(cmd->data[0], my_built[i], 0););
    free(my_built);
    return ((i == 5) ? (10) : my_redirection[i](cmd->data, env));
}

char check_command(cmd_t *cmd, env_t *env)
{
    if (cmd->data[0] == NULL || cmd->data == NULL)
        return (0);
    return ((my_builtin(cmd, env) == 10) ? (10) : (0));
}
