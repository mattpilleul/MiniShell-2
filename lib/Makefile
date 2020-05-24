##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Make binary of pushswap
##

NAME	= libmy.a

SRCS	= my_putchar.c \
	  my_getnbr.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_realloc.c \
	  my_memset.c \
	  my_str_isalpha.c	\
	  gnl/get_next_line.c \
	  concat.c \
	  my_strncmp.c \
	  my_str_to_wordtab.c \
	  my_putstr_err.c

MOD	= $(addprefix src/, $(SRCS:.c=.o))

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -Iinclude/

RM	= rm -rf

all:	$(NAME)

$(NAME):  $(MOD)
	  ar rc $(NAME) $(MOD)

clean:	
	$(RM) $(MOD)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
