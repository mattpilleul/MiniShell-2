/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <sys/wait.h>
#include "my.h"

void manage_sig(int wstat)
{
    int status = 0;

    while (wstat-- > 0){
        if (wait(&status) == -1)
            my_putstr("Error");
        if (WTERMSIG(status) == 136 || WTERMSIG(status) == 8)
            my_putstr("Floating exception (core dumped)\n");
        if (WTERMSIG(status) == 139 || WTERMSIG(status) == 11)
            my_putstr_err("Segmentation fault (core dumped)\n");
    }
}
