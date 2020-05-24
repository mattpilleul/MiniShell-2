/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "get_next_line.h"
#include "my.h"

void aff_prompt(env_t *env)
{
    my_putstr("mattpilleul $> ");
}

char loop_shell(char *buffer, env_t *env)
{
    char **size;
    char *error;
    int	i = -1;

    (void)(*env);
    size = separe_wordtab(buffer, ';');
    while (size[++i]){
        error = parsing_prog(size[i], env);
        if (error != 0)
      	    my_putstr(error);
    }
    free_manager(size);
    return (0);
}

void my_interupt(int c)
{
    (void)c;
    my_putstr("\nmattpilleul $> ");
}

void intercept(void)
{
    if (signal(SIGINT, my_interupt) == SIG_ERR)
        my_puterror("Error: Problem SIGINT.\n");
}

int	main(int argc, char **argv, char **envv)
{
    env_t *env;
    char *buffer;

    if (envv[0] == NULL)
        envv[0] = NULL;
    env = start_env(envv);
    aff_prompt(env);
    while ((buffer = get_next_line(0))){
        loop_shell(buffer, env);
        aff_prompt(env);
        intercept();
        free(buffer);
    }
    return (0);
}
