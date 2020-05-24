/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#ifndef MY_H_
#define MY_H_

#include "lib.h"

typedef struct red_s
{
    char **tab;
    int	redi_left;
    int	redi_right;
    int	redi_two_r;
    int	redi_two_l;
} red_t;

typedef struct cmd_s
{
    char **data;
    int	fd;
    int	output;
    int	nb_redirection;
    red_t **redirection;
    int	input;
    struct cmd_s *next;
    struct cmd_s *prev;
} cmd_t;

typedef struct init_s
{
    cmd_t *previous;
    cmd_t *next;
} init_t;

typedef struct env_s
{
    char *data;
    struct env_s *next;
    struct env_s *prev;
} env_t;

void manage_sig(int);
void start_my_prg(cmd_t *);
void init_redirection(cmd_t **, int);
int main_execve(cmd_t *, red_t **);
void close_filedesc(int *);
char *initiat_red(cmd_t **);
char **separe_wordtab(char *, char);
char **manage_space_red(char **);
env_t *create_env();
env_t *start_env(char **);
env_t *add_env(env_t *, char *, char *);
char *parsing_prog(char *, env_t *);
void my_puterror(char *);
char error_cd(char *, char *);
char error_execve(char *, char **);
char builtin_exit(char **, env_t *);
char *check_options_cd(env_t *, char *, char *);
char builtin_cd(char **, env_t *);
char builtin_env(char **, env_t *);
char builtin_unsetenv(char **, env_t *);
char builtin_setenv(char **, env_t *);
int	count_env(env_t *, env_t *);
void free_manager(char **);
void my_putcerr(char);
void my_putstr_err(char *);
int	compt_list(env_t *, env_t *);
void display_env(env_t *);
char **manage_env(env_t *);
char *search_env(env_t *, char *);
env_t *update_env(env_t *, char *, char *);
void remove_env(env_t *, char *);
char *use_pers_path(char *);
char *verif_path(char *);
char *my_find_element(char *, env_t *);
char check_command(cmd_t *, env_t *);
int	my_builtin(cmd_t *, env_t *);
int	start_execve(cmd_t *, red_t **, env_t *, int *);
char *permission_man(char **, char **, char **, int);
void initialize_prog(init_t *);
int add_initialize(init_t *, cmd_t *);
int	my_insert_pushback(init_t *, cmd_t *);
int	my_strlen(char *);
char *my_strdup(char *);
char *my_strcat(char *, char *, int);
int	my_strlen(char *);
char *my_strdup(char *);
char my_strcmp(char *, char *, int);
int my_getnbr(char *);
int	my_str_isalpha(char *);

#endif