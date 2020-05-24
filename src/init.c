/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

void init_redirection(cmd_t **cmd, int z)
{
    (*cmd)->redirection[z]->redi_right = 0;
    (*cmd)->redirection[z]->redi_left = 0;
    (*cmd)->redirection[z]->redi_two_r = 0;
}

void start_my_prg(cmd_t *tampon)
{
    tampon->output = -1;
    tampon->input = -1;
    tampon->fd = -1;
}
