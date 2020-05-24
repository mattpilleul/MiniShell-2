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

char *get_pwd(void)
{
    char *pwd = malloc(sizeof(char *) * 1024);

    if (pwd == NULL)
        my_puterror("Error memory(5)");
    getcwd(pwd, 1024);
    return (pwd);
}

char *update_env_cd(env_t *env, char *new)
{
    char *buffer;

    if (search_env(env, new) != NULL){
        if ((buffer = malloc(sizeof(char *) * 1024)) == NULL)
      	    my_puterror("Error memory(5)");
        getcwd(buffer, 1024);
        env = update_env(env, my_strcat(my_strcat(new, "=", 0),
        buffer, 0), new);
        free(buffer);
    }
    return (NULL);
}

char *check_options_cd(env_t *env, char *cmd, char *oldpwd)
{
    char *directory;

    if (cmd == NULL || my_strcmp(cmd, " ", 0)
    || my_strcmp(cmd, "\t", 0) || my_strcmp(cmd, "\0", 0))
        directory = search_env(env, "HOME");
    else if (my_strcmp(cmd, "-", 0))
        directory = (oldpwd == NULL) ? "\0" : oldpwd;
    else if (my_strcmp(cmd, "~", 0))
        directory = search_env(env, "HOME");
    else
        directory = cmd;
    return (directory);
}

char builtin_cd(char **cmd, env_t *env)
{
    static char *old_pwd;
    char *directory;

    if ((directory = check_options_cd(env, cmd[1], old_pwd)) == NULL)
        return (0);
    if (access(directory, F_OK) == -1)
        return (error_cd("No such file or directory.", directory));
    if (access(directory, R_OK) == -1)
        return (error_cd("Permission denied.", directory));
    old_pwd = get_pwd();
    if (chdir(directory) == -1)
        return (error_cd("Not a directory.", directory));
    update_env_cd(env, "PWD");
    return (0);
}