/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redi_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 12:46:33 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/26 16:55:09 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <fcntl.h>
#include <stdlib.h>

static void		redi_left(char *path, char **cmd_arg, char ***env, char **split)
{
	int		fdf[2];
	int		ret;

	pipe(fdf);
	ret = open(split[1], O_RDONLY);
	close(fdf[0]);
	dup2(fdf[0], 1);
	dup2(ret, 0);
	close(fdf[1]);
	execve(path, cmd_arg, *env);
	return ;
}

static void		do_redi_first(char *cmd, int *execve_flag, char ***env)
{
	char	**cmd_arg;
	char	*path;
	char	**split;
	char	*new;
	int		i;

	i = 3;
	split = ft_strsplit(cmd, ' ');
	new = ft_strdup(split[2]);
	while (split[i++])
		new = ft_strjoin(new, split[i]);
	cmd_arg = get_clean_arg(new, *env);
	if ((path = get_path_cmd(*env, cmd_arg[0])) == NULL)
	{
		ft_error(cmd_arg[0]);
		*execve_flag = -1;
		return ;
	}
	if ((access(split[1], F_OK | W_OK) == 0) || (access(split[1], R_OK) != -1))
		redi_left(path, cmd_arg, env, split);
	else
		ft_error_redi(split[1]);
}

static void		ft_redi_left(char *cmd, int *execve_flag, char ***env)
{
	char	**split;
	char	**cmd_arg;
	char	*path;

	if (cmd[0] == '<')
	{
		do_redi_first(cmd, execve_flag, env);
		return ;
	}
	split = ft_strsplit(cmd, '<');
	split[1] = ft_strtrim(split[1]);
	cmd_arg = get_clean_arg(split[0], *env);
	if ((path = get_path_cmd(*env, cmd_arg[0])) == NULL)
	{
		ft_error(cmd_arg[0]);
		*execve_flag = -1;
		return ;
	}
	if ((access(split[1], F_OK | W_OK) == 0) || (access(split[1], R_OK) != -1))
		redi_left(path, cmd_arg, env, split);
	else
		ft_error_redi(split[1]);
}

int				exec_redi_left(char *cmd, char ***env, int *execve_flag)
{
	pid_t		pid;

	if (ft_strsrch(cmd, '<') != -1)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
		{
			ft_redi_left(cmd, execve_flag, env);
			exit(1);
		}
		else
			waitpid(pid, execve_flag, WUNTRACED);
		return (0);
	}
	return (1);
}
