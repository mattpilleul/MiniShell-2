/*
** EPITECH PROJECT, 2019
** Projet
** File description:
** getnextline
*/

#ifndef LIB_H_
#define LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	my_getnbr(char *);
void my_putchar(char);
int	my_put_nbr(int);
int	my_putstr(char *);
void my_putstr_err(char *);
int	my_strlen(char *);
char *my_realloc(char *, int);
void *my_memset(void *, int, int);
char *concat(char *, char *);
char my_strncmp(char *, char *, int);
char **my_str_to_wordtab(char *, char);
int	my_str_isalpha(char *);

#endif
