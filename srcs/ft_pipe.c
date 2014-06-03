/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 11:23:53 by fperret           #+#    #+#             */
/*   Updated: 2014/03/25 11:19:49 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

int				do_pipe(char ***env, char *command, int *execve_flag)
{
	char	**split_pipe;
	int		pi[2];
	pid_t	pid;

	split_pipe = ft_strsplit(command, '|');
	if (call_pipe(pi) == NULL)
		return (-1);
	pid = fork();
	if (pid == -1)
		ft_fork_error(pi);
	if (pid == 0)
	{
		if (exec_child(env, split_pipe[1], pi, execve_flag) == 2)
			return (2);
	}
	else
	{
		if (exec_father(env, split_pipe[0], pi, execve_flag) == 3)
			return (3);
	}
	ft_tabfree(split_pipe);
	return (1);
}

void			exec_pipe(char ***env, char *command, int *execve_flag)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		do_pipe(env, command, execve_flag);
		exit(1);
	}
	else
		waitpid(pid, execve_flag, WUNTRACED);
}
