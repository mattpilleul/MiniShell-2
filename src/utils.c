/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void my_putcerr(char c)
{
    write(2, &c, 1);
}

void my_putstr_err(char *str)
{
    int	i = -1;

    while (str && str[++i] != '\0')
        my_putcerr(str[i]);
}

int	compt_list(env_t *tampon, env_t *env)
{
    int	count = 0;

    for (; tampon != env; tampon = tampon->next){
        ++count;
    }
    return (count);
}