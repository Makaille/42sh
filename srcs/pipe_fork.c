/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:09:38 by fperret           #+#    #+#             */
/*   Updated: 2014/03/26 16:11:58 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

static void		ft_free_for_pipe(char **args, char **split, char *path, int mod)
{
	if (mod == 0)
	{
		ft_tabfree(args);
		free(path);
	}
	else if (mod == 1)
		ft_tabfree(split);
}

static int		ft_child(char ***env, char *cmd, int *pi, int *execve_flag)
{
	char	**cmd_arg;
	char	*path;

	cmd_arg = get_clean_arg(cmd, *env);
	path = get_path_cmd(*env, cmd_arg[0]);
	close(pi[1]);
	if (dup2(pi[0], 0) == -1)
		return (-1);
	close(pi[0]);
	if ((ft_rd(cmd, env, execve_flag) == 1) && (builtin(env, cmd_arg) == 0))
		execve(path, cmd_arg, *env);
	ft_free_for_pipe(cmd_arg, NULL, path, 0);
	return (2);
}

int				exec_child(char ***env, char *cmd, int *pi, int *execve_f)
{
	char	**cmd_arg;
	char	*path;

	if (*execve_f != FAIL)
	{
		cmd_arg = get_clean_arg(cmd, *env);
		if (((path = get_path_cmd(*env, cmd_arg[0])) == NULL)
			&& (ft_rd(cmd, env, execve_f) == 1))
		{
			ft_error(cmd_arg[0]);
			*execve_f = -1;
			return (1);
		}
		else
			return (ft_child(env, cmd, pi, execve_f));
	}
	return (3);
}

static int		ft_father(char ***env, char *cmd, int *pi, int *execve_flag)
{
	char	**cmd_arg;
	char	*path;

	cmd_arg = get_clean_arg(cmd, *env);
	path = get_path_cmd(*env, cmd_arg[0]);
	close(pi[0]);
	if (dup2(pi[1], 1) == -1)
		return (-1);
	close(pi[1]);
	if ((ft_rd(cmd, env, execve_flag) == 1) && (builtin(env, cmd_arg) == 0))
		execve(path, cmd_arg, *env);
	return (3);
}

int				exec_father(char ***env, char *cmd, int *pi, int *execve_f)
{
	char	**cmd_arg;
	char	*path;

	cmd_arg = get_clean_arg(cmd, *env);
	if (((ft_strsrch(cmd, '>') == -1) || (ft_strsrch(cmd, '<') == -1))
		&& ((path = get_path_cmd(*env, cmd_arg[0])) == NULL))
	{
		ft_error(cmd_arg[0]);
		*execve_f = -1;
		ft_tabfree(cmd_arg);
		free(path);
		return (1);
	}
	else
		return (ft_father(env, cmd, pi, execve_f));
}
