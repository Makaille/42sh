# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguilbau <mguilbau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 16:08:49 by mguilbau          #+#    #+#              #
#    Updated: 2014/03/27 17:56:22 by mroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 42sh

LIB				= libft/

SRCS			=	srcs/main.c					\
					srcs/ft_clean.c				\
					srcs/ft_error.c				\
					srcs/ft_operator.c			\
					srcs/builtin.c				\
					srcs/builtin_cd.c			\
					srcs/builtin_setenv.c		\
					srcs/builtin_unsetenv.c		\
					srcs/ft_exec.c				\
					srcs/tools.c				\
					srcs/ft_strsplit_index.c	\
					srcs/error2.c				\
					srcs/ft_pipe.c				\
					srcs/ft_redi_right.c		\
					srcs/ft_redi_left.c			\
					srcs/ft_doublerd.c			\
					srcs/ft_rd_all.c			\
					srcs/pipe_fork.c			\

OBJS			= $(SRCS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I$(I)

LFLAG			= -L libft/ -lft

I				= ./includes/

all: $(NAME)

$(NAME): $(OBJS)

	@echo "\033[1;33m"
	@make -C $(LIB)
	@echo "\033[1;37m"
	$(CC) $(CFLAGS) $(LFLAG) -o $(NAME) $(SRCS)
	@echo "Compilation complete √"

clean:

	@make -C $(LIB) clean
	@$(RM) $(OBJS)
	@echo  "\033[1;34m"
	@echo "Clean...\033[1;32m done"


fclean:		clean

	@make -C $(LIB) fclean
	@$(RM) $(NAME)
	@echo  "\033[1;34m"
	@echo "Fclean...\033[1;32m done"

re:			fclean all

.PHONY : fclean clean all
