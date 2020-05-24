/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <fcntl.h>
#include "my.h"

void close_filedesc(int *pipefd)
{
    int i = -1;

    if (pipefd != NULL)
        while (pipefd[++i] != 0)
            close(pipefd[i]);
}

int	one_redir(red_t *redi, int errcd, int nfiled)
{
    int	fd = 0;

    if ((fd = open(redi->tab[0], errcd, 0644)) == -1){
        if (nfiled == 0){
            my_putstr(redi->tab[0]);
            my_putstr(": No such file or directory.\n");
        } else
            my_putstr("Error open\n");
        exit (0);
    }
    if (dup2(fd, nfiled) == -1)
        my_putstr("error dup2");
    return (fd);
}

int	main_execve(cmd_t *cmd, red_t **redi)
{
    int	z = -1;

    (cmd->input != -1) ? dup2(cmd->input, 0) : (0);
    (cmd->output != -1) ? dup2(cmd->output, 1) : (0);
    if (redi != NULL)
        for (z = -1; ++z < cmd->nb_redirection;){
            if (redi[z]->redi_two_r == 1)
                one_redir(redi[z], O_CREAT | O_RDWR | O_APPEND, 1);
            else if (redi[z]->redi_left == 1)
                one_redir(redi[z], O_RDONLY, 0);
            else if (redi[z]->redi_right == 1)
                one_redir(redi[z], O_CREAT | O_RDWR | O_TRUNC, 1);
        }
    return (0);
}