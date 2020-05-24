/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get next line of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/get_next_line.h"

int check_first_char(int fd, char *character)
{
    static char *back_up_result = NULL;
    char *result = malloc(READ_SIZE + 1);
    static int lenght = 0;

    if (lenght == 0){
        lenght = read(fd, result, READ_SIZE);
        back_up_result = result;
        if (back_up_result[0] == '\0' && back_up_result[1] == '\0'){
            *character = back_up_result[0];
            back_up_result = back_up_result + 1;
            lenght = lenght - 1;
            return (0);
        }
    }
    *character = back_up_result[0];
    back_up_result = back_up_result + 1;
    lenght--;
}

char *get_next_line(int fd)
{
    char *result = malloc(READ_SIZE + 1);
    int i;
    char character = 0;

    if (result == NULL)
        return (NULL);
    check_first_char(fd, &character);
    if (fd == -1)
        return (NULL);
    if (character == 0)
        return (NULL);
    for (i = 0; character != '\n' && character != '\0'; i++){
        result[i] = character;
        check_first_char(fd, &character);
    }
    result[i] = '\0';
    return (result);
}
