/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublerd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:24:24 by fperret           #+#    #+#             */
/*   Updated: 2014/03/25 11:12:36 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

static void		doublerd(char *path, char **cmd_arg, char ***env, char **split)
{
	int		fdf[2];
	int		ret;

	pipe(fdf);
	ret = open(split[1], O_RDWR | O_CREAT | O_APPEND);
	if (access(split[1], W_OK) == -1)
		chmod(split[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(fdf[1]);
	dup2(fdf[0], 0);
	dup2(ret, 1);
	close(fdf[0]);
	execve(path, cmd_arg, *env);
	close(ret);
}

static void		ft_doublerd(char *command, int *execve_flag, char ***env)
{
	char	**split;
	char	**cmd_arg;
	char	*path;

	split = ft_strsplit(command, '>');
	split[1] = ft_strtrim(split[1]);
	cmd_arg = get_clean_arg(split[0], *env);
	if ((path = get_path_cmd(*env, cmd_arg[0])) == NULL)
	{
		ft_error(cmd_arg[0]);
		*execve_flag = -1;
		return ;
	}
	if ((access(split[1], F_OK | W_OK) == 0) || (access(split[1], F_OK) == -1))
		doublerd(path, cmd_arg, env, split);
	else
		ft_error_redi(split[1]);
}

int				exec_doublerd(char *cmd, char ***env, int *execve_flag)
{
	pid_t		pid;

	if (ft_check_redi(cmd) == 1)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
		{
			ft_doublerd(cmd, execve_flag, env);
			exit(1);
		}
		else
			waitpid(pid, execve_flag, WUNTRACED);
		return (0);
	}
	return (1);
}
