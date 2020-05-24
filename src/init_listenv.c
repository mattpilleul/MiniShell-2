/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

env_t *create_env(void)
{
    env_t *noeud = malloc(sizeof(env_t));

    if (noeud == NULL)
        my_puterror("Error with a memory allocation\n");
    noeud->next = noeud;
    noeud->prev = noeud;
    return (noeud);
}

env_t *add_env(env_t *env, char *str, char *str2)
{
    env_t *tampon;
    int	i = 0;
    int	z = 0;

    tampon = create_env();
    if ((tampon->data = malloc(my_strlen(str) + my_strlen(str2) + 2)) == NULL)
        my_puterror("Problem with a memory allocation\n");
    for (; str2 && str2[i] != '\0';)
        tampon->data[z++] = str2[i++];
    tampon->data[z++] = '=';
    for (i = 0; str && str[i] != '\0';)
        tampon->data[z++] = str[i++];
    tampon->data[z] = '\0';
    tampon->prev = env->prev;
    tampon->next = env;
    env->prev->next = tampon;
    env->prev = tampon;
    return (env);
}

env_t *start_env(char **env)
{
    env_t *tampon = create_env();
    env_t *tampon2;
    int	i = 0;
    int	j = 0;

    for (i = 0; env[i] != NULL; i++){
        j = -1;
        tampon2 = create_env();
        if ((tampon2->data = malloc(my_strlen(env[i]) + 1)) == NULL)
            my_puterror("Error memory");
        for (; env[i][++j] != '\0';)
            tampon2->data[j] = env[i][j];
        tampon2->data[j] = '\0';
        tampon2->prev = tampon->prev;
        tampon2->next = tampon;
        tampon->prev->next = tampon2;
        tampon->prev = tampon2;
    }
    return (tampon);
}