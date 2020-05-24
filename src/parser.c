/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void add_pipe(int **pipefd, cmd_t *cmd, int fd[2], int j)
{
    if ((pipe(fd)) == -1)
        exit (0);
    cmd->output = fd[1];
    (*pipefd)[j] = fd[0];
    (*pipefd)[j + 1] = fd[1];
    (*pipefd)[j + 2] = 0;
}

void my_pipe_man(char **tampon, init_t *init, int **pipefd, int nb_pipe)
{
    cmd_t *cmd;
    int	fd[2];
    int	i = 0;
    int	j = 0;

    if ((cmd = malloc(sizeof(cmd_t))) == NULL)
        exit (0);
    start_my_prg(cmd);
    for (; nb_pipe > 0; nb_pipe -= 1){
        add_pipe(pipefd, cmd, fd, j);
        cmd->data = my_str_to_wordtab(tampon[i++], ' ');
        add_initialize(init, cmd);
        cmd->input = fd[0];
        j += 2;
    }
    cmd->output = -1;
    cmd->data = my_str_to_wordtab(tampon[i], ' ');
    add_initialize(init, cmd);
}

char *show_cmd(init_t *init, char **tampon, int **pipefd)
{
    char *error;
    cmd_t *cmd;
    int	nbr_pipe;
    int	i;

    (*pipefd) = NULL;
    nbr_pipe = -1;
    for (i = -1; tampon[++i] != '\0';)
        nbr_pipe += 1;
    if (nbr_pipe > 0)
        if ((*(pipefd) = malloc(sizeof(int) * (nbr_pipe * 2 + 1))) == NULL)
            exit (0);
    my_pipe_man(tampon, init, pipefd, nbr_pipe);
    cmd = init->previous;
    if ((error = initiat_red(&cmd)) != 0)
        return (error);
    return (0);
}

char *parsing_prog(char *tab, env_t *env)
{
    char **cmd;
    int	*pipefd;
    cmd_t *tampon;
    init_t init;
    int	nb_exec = 0;
    char *error;

    initialize_prog(&init);
    cmd = separe_wordtab(tab, '|');
    if ((error = show_cmd(&init, cmd, &pipefd)) != 0)
        return (error);
    for (tampon = init.previous; tampon != NULL; tampon = tampon->next)
        if (start_execve(tampon, tampon->redirection, env, pipefd) != 10)
            nb_exec += 1;
    close_filedesc(pipefd);
    manage_sig(nb_exec);
    return (0);
}