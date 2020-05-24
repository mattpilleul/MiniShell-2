/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void free_manager(char **size)
{
    int i = 0;

    if (size != NULL){
        while (size[i] != '\0')
      	    free(size[i++]);
        free(size);
    }
}
