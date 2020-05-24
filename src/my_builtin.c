/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char manage_exit(char **cmd)
{
    int	i = -1;
    int	compteur = -1;

    for (compteur = -1; cmd[++compteur];);
    if (cmd[1] != NULL)
        for (; cmd[1][++i] != '\0';){
            if ((cmd[1][i] >= '!' && cmd[1][i] < '-')
            || (cmd[1][i] > '-' && cmd[1][i] < '0')
            || (cmd[1][i] > '9' && cmd[1][i] <= '~')){
                my_putstr("Error syntax\n");
                return (1);
            }
        }
    if (compteur > 2){
        my_putstr("Error syntax\n");
        return (1);
    }
    return (0);
}

char builtin_exit(char **cmd, env_t *env)
{
    env_t *tampon;
    int	status = 0;

    if (manage_exit(cmd))
        return (0);
    if (cmd[1] != NULL)
        status = my_getnbr(cmd[1]);
    if (env != NULL){
        for (tampon = env->next; tampon != env; tampon = tampon->next)
            free(tampon->data);
        free(tampon);
    }
    free_manager(cmd);
    exit(status);
    return (0);
}

char builtin_setenv(char **cmd, env_t *env)
{
    int i = -1;

    while (cmd[++i]);
    if (my_str_isalpha(cmd[1]) == 84){
        my_putstr("setenv: Variable name must contain ");
        my_putstr("alphanumeric characters.\n");
        return (0);
    }
    if (i > 3)
        my_putstr("setenv: Too many arguments\n");
    else if (cmd[1] != NULL){
        remove_env(env, cmd[1]);
        env = add_env(env, cmd[2], cmd[1]);
    } else
        builtin_env(cmd, env);
    return (0);
}

char builtin_unsetenv(char **cmd, env_t *env)
{
    int	i = 1;

    if (cmd[i] != NULL)
        while (cmd[i] != NULL)
            remove_env(env, cmd[i++]);
    else
        my_putstr("unsetenv: Too few arguments.\n");
    return (0);
}

char builtin_env(char **cmd, env_t *env)
{
    if (cmd[1] != NULL)
        my_putstr("env : Too many arguments\n");
    else if (env != NULL)
        display_env(env);
    return (0);
}
