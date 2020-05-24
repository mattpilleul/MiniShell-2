/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

void end_red(char **tampon, int h, int *y, cmd_t **cmd)
{
    int j = 0;

    if (tampon[h + 2] && tampon[h + 2][j] != '<' && tampon[h + 2][j] != '>')
        h += 2;
    if (tampon[h][j] != '\0' && tampon[h][j] != '>' && tampon[h][j] != '<')
        for (; tampon[h]; h += 1){
            if (((*cmd)->data[(*y)] = malloc(sizeof(char) * 30)) == NULL)
                exit (0);
            for (j = 0; tampon[h][j] != '\0'; j+= 1)
                (*cmd)->data[(*y)][j] = tampon[h][j];
            (*cmd)->data[(*y)][j] = '\0';
            (*y) += 1;
        }
}

void redirect(cmd_t **cmd, char **tampon, int i, int z)
{
    int	y;
    int	h;

    if (((*cmd)->redirection[z] = (red_t *)malloc(sizeof(red_t))) == NULL)
        exit (0);
    init_redirection(cmd, z);
    (*cmd)->nb_redirection += 1;
    if (tampon[i + 1])
        (*cmd)->redirection[z]->tab = separe_wordtab(tampon[i + 1], ' ');
    for (y = -1; (*cmd)->data[++y];)
        (*cmd)->data[y] = '\0';
    for (h = 0, y = 0; tampon[h][0] != '>' && tampon[h][0] != '<';
    y += 1, h += 1)
        (*cmd)->data[y] = tampon[h];
    end_red(tampon, h, &y, cmd);
    (*cmd)->data[y] = '\0';
}

char *loop_redirect(cmd_t **cmd, char **tampon, int i, int *z)
{
    if ((tampon[i][0] == '>' || tampon[i][0] == '<')){
        redirect(cmd, tampon, i, *z);
        (*z) += 1;
        (tampon[i][0] == '>' && tampon[i][1] == '>') ? ((*cmd)->redirection
        [*z - 1]->redi_two_r = 1) : (tampon[i][0] == '<' && tampon[i][1] ==
        '<') ? ((*cmd)->redirection[*z - 1]->redi_two_l = 1) :
        (tampon[i][0] == '>' && tampon[i][1] != '>') ? ((*cmd)->redirection
        [*z - 1]->redi_right = 1) : (tampon[i][0] == '<' && tampon[i][1]
        != '<') ? ((*cmd)->redirection[*z - 1]->redi_left = 1) : (0);
    }
    return (0);
}

char *check_redirection(cmd_t **cmd, char **tampon)
{
    int i = -1;
    int	z = 0;

    if (((*cmd)->redirection = (red_t **)malloc(
        sizeof(red_t *) * 20)) == NULL)
        exit (0);
    for (i = -1; tampon[++i];)
        loop_redirect(cmd, tampon, i, &z);
    return (0);
}

char *initiat_red(cmd_t **cmd)
{
    char *error;
    char **tampon;
    int	i;
    int	compteur = 0;

    for (; (*cmd) != NULL;){
        tampon = manage_space_red((*cmd)->data);
        (*cmd)->nb_redirection = 0;
        (*cmd)->redirection = NULL;
        for (i = -1; tampon[++i];)
            compteur += (tampon[i][0] == '>' || tampon[i][0] == '<') ? 1 : 0;
            if ((tampon[i - 1][0] == '>' || tampon[i - 1][0] == '<'))
                return ("Ambiguous input redirect.\n");
            if (compteur > 0)
                if ((error = check_redirection(cmd, tampon)) != 0)
                    return (error);
            (*cmd) = (*cmd)->next;
    }
    return (0);
}
