##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Make binary of pushswap
##

NAME		=	mysh

SRC		= 	main.c \
			utils.c \
			parser.c \
			init_listenv.c \
			separe.c \
			check_command.c \
			utils_env.c \
			my_exec.c \
			my_strutils.c \
			my_builtin.c \
			my_builtin_cd.c \
			my_free.c \
			init.c \
			my_str_isalpha.c	\
			my_puterror.c \
			redirection.c \
			my_exec_canals.c \
			wait.c \
			list.c 

MOD		=	$(addprefix src/, $(SRC:.c=.o))

LIB		=	-Llib/
LIB		+=	-Ilib/include -Llib/ -lmy

LIBMYUTILS_MAKE	=	make -C lib/
LIBMYUTILS	=	lib/libmy.a

CFLAGS		+=	-g
CFLAGS		+=	-Iinclude/
CFLAGS		+=	$(LIB)

LDFLAGS		=	$(LIB)

all:		$(LIBMYUTILS) $(NAME)

$(NAME):	$(MOD)
		@cc $(MOD) -o $(NAME) $(LDFLAGS)

$(LIBMYUTILS):
	 	$(LIBMYUTILS_MAKE)

clean		:
		 rm -rf $(MOD)
		 $(LIBMYUTILS_MAKE) clean

fclean		: clean
		  rm -rf $(NAME)
		  $(LIBMYUTILS_MAKE) fclean

re:		fclean all

.PHONY:		all clean fclean re
