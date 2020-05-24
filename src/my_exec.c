/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

char **manage_alias(char **cmd)
{
    if (my_strcmp(cmd[0], "clean", 0))
        return (my_str_to_wordtab("rm -f", ' '));
    return (cmd);
}

char example_file(char operat, char operat2, char **cmd)
{
    if (operat != ' '){
        if (cmd[0][0] == operat && cmd[0][1] == operat2
        && (access(cmd[0], F_OK) != -1))
            return (0);
    } else if (operat == ' ')
        if (cmd[0][0] == operat2 && (access(cmd[0], F_OK) != -1))
            return (0);
    return (1);
}

char *permission_man(char **filepath, char **cmd, char **tab, int i)
{
    char *name = NULL;

    if (!example_file('.', '/', cmd)){
        if (((name = cmd[0]) && (access(cmd[0], R_OK | X_OK) == -1))
        || (execve(name, cmd, tab) == -1))
            return ("Permissions denied.");
    } else if (cmd[0][0] != '/' && cmd[0][0] != '.')
        name = my_strcat(filepath[i++], cmd[0], 1);
    else if (!example_file(' ', '/', cmd)){
        if (((name = cmd[0]) && (access(cmd[0], R_OK | X_OK) == -1))
        || (execve(name, cmd, tab) == -1))
            return ("Permissions denied.");
    } if (name != NULL){
        execve(name, cmd, tab);
        permission_man(filepath, cmd, tab, i);
    } else
        return (NULL);
    return (0);
}

void manage_error(char *error, char **cmd, char **tab)
{
    error_execve(error, cmd);
    free_manager(cmd);
    free_manager(tab);
    exit (1);
}

int	start_execve(cmd_t *cmd, red_t **redirection,
env_t *env, int *pipefd)
{
    char **size;
    char *error;
    pid_t pid;

    if (check_command(cmd, env) != 10)
        return (10);
    else if ((pid = fork()) == 0){
        main_execve(cmd, redirection);
        close_filedesc(pipefd);
        size = manage_env(env);
        error = permission_man(
        my_str_to_wordtab(use_pers_path(search_env(env, "PATH")), ':'),
        manage_alias(cmd->data), size, 0);
        manage_error(error, cmd->data, size);
    } else if (pid == -1)
        my_putstr("Error with pid");
    return (0);
}
