/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 19:17:07 by fperret           #+#    #+#             */
/*   Updated: 2014/03/27 11:10:14 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

char	*get_path_cmd(char **env, char *cmd)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	if ((tmp = search_line(&env, "PATH=")) != NULL)
	{
		tmp = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
		path = ft_strsplit(tmp, ':');
		if (access(cmd, F_OK) == 0)
			return (cmd);
		while (path[i])
		{
			path[i] = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path[i], cmd);
			if (access(path[i], F_OK) == 0)
				return (path[i]);
			i++;
		}
		free(tmp);
	}
	return (NULL);
}

void	ft_exec_cmd(char *path, char **cmd_arg, char **env, int *execve_flag)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		execve(path, cmd_arg, env);
		exit(1);
	}
	else
		waitpid(pid, execve_flag, WUNTRACED);
}

char	**ft_path(char ***env, char *cmd)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	if ((tmp = search_line(env, "PATH=")) != NULL)
	{
		tmp = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
		path = ft_strsplit(tmp, ':');
		while (path[i])
		{
			path[i] = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path[i], cmd);
			i++;
		}
		free(tmp);
		return (path);
	}
	free(tmp);
	return (NULL);
}

void	ft_execute_cmd(char **path, char **cmd, char **env, int *flagados)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		execve(cmd[0], cmd, env);
		if (path != NULL)
		{
			while (path[i])
			{
				execve(path[i], cmd, env);
				i++;
			}
		}
		ft_error(cmd[0]);
		exit(1);
	}
	else
		waitpid(pid, flagados, WUNTRACED);
}

void	ft_launch_exec(char *command, char ***env, int *execve_flag)
{
	char	**path;
	char	**cmd_arg;

	if (ft_strsrch(command, '|') != -1)
		exec_pipe(env, command, execve_flag);
	else
	{
		cmd_arg = get_clean_arg(command, *env);
		if (((path = ft_path(env, cmd_arg[0])) == NULL)
				&& ft_strcmp(command, "exit") != 0)
			ft_putendl("Set a good path or you will take expensive.");
		if ((ft_rd(command, env, execve_flag) == 1)
				&& (builtin(env, cmd_arg) == 0))
		{
			ft_execute_cmd(path, cmd_arg, *env, execve_flag);
			if (path)
				ft_tabfree(path);
		}
	}
}
