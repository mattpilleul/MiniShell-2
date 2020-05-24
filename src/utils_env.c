/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

char *search_env(env_t *env, char *string)
{
    env_t *tampon;
    int	i;

    if (env->prev->data == NULL)
        return (NULL);
    for (tampon = env->next; tampon != env; tampon = tampon->next){
        for (i = 0; string[i] == tampon->data[i];){
            i++;
            if (tampon->data[i] == '=' && (my_strlen(string) == i))
                return (&tampon->data[i + 1]);
        }
    }
    return (NULL);
}

env_t *update_env(env_t *env, char *directory, char *str)
{
    env_t *tampon;
    int	i;
    int	z = 0;

    for (tampon = env->next; tampon != env; tampon = tampon->next){
        for (i = 0; tampon->data[i] == str[i]; ++i);
        if (tampon->data[i] == '='){
            i = 0;
            if ((tampon->data = malloc(sizeof(char) *
            my_strlen(directory) + 2)) == NULL)
                my_puterror("Error memory\n");
            for (z = 0; directory[z] != '\0';)
                tampon->data[i++] = directory[z++];
            tampon->data[i] = '\0';
        }
    }
    return (tampon);
}

char **manage_env(env_t *env)
{
    env_t *tampon;
    char **tab;
    int	i;

    if (env->prev->data == NULL)
        return (NULL);
    tampon = env->next;
    if ((tab = malloc(sizeof(char *) * (compt_list(tampon, env) + 1)))
    == NULL)
        my_puterror("Error memory\n");
    i = -1;
    for (; tampon != env; tampon = tampon->next)
        tab[++i] = my_strdup(tampon->data);
    tab[i] = '\0';
    return (tab);
}

void display_env(env_t *env)
{
    env_t *tampon;

    for (tampon = env->next; tampon != env; tampon = tampon->next){
        my_putstr(tampon->data);
        my_putstr("\n");
    }
}

void remove_env(env_t *env, char *cmd)
{
    env_t *tampon;

    for (tampon = env->next; tampon != env && !my_strcmp(tampon->data,
    cmd, 1); tampon = tampon->next);
    if (tampon != env){
        tampon->prev->next = tampon->next;
        tampon->next->prev = tampon->prev;
        free(tampon->data);
        free(tampon);
    }
}