/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void initialize_prog(init_t *init)
{
    init->previous = NULL;
    init->next = NULL;
}

int	new_pipe(cmd_t **init, cmd_t *cmd)
{
    (*init)->output = cmd->output;
    (*init)->input = cmd->input;
    (*init)->fd = cmd->fd;
    return (0);
}

int	add_initialize(init_t *init, cmd_t *cmd)
{
    cmd_t *tampon = malloc(sizeof(cmd_t));

    if (tampon == NULL)
        return (0);
    tampon->data = cmd->data;
    tampon->output = cmd->output;
    tampon->input = cmd->input;
    tampon->fd = cmd->fd;
    tampon->prev = init->next;
    tampon->next = NULL;
    if (init->next)
        init->next->next = tampon;
    else
        init->previous = tampon;
    init->next = tampon;
    return (1);
}