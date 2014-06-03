/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:59:31 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/27 12:06:54 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>
#include <signal.h>

static void		ctrl_c(int sig)
{
	signal(sig, SIG_IGN);
	ft_putstr("\n42sh -> ");
}

static void		ft_treat_cmd(char ***env, char *cmd, int ampersand, int or_flag)
{
	int		execve_flag;

	execve_flag = 0;
	if (ft_error_null_command(cmd) == 1)
	{
		ft_putendl("Invalid null command.");
		return ;
	}
	if (ampersand == 1 && or_flag == 1)
		ampersand_and_or(env, cmd, &execve_flag);
	else if (ampersand == 1 && or_flag == 0)
		split_exec_ampersand(env, cmd, &execve_flag);
	else if (or_flag == 1 && ampersand == 0)
		no_ampersand_and_or(env, cmd, &execve_flag);
	else
		ft_launch_exec(cmd, env, &execve_flag);
}

static void		ft_do_comma(char **command, char ***env)
{
	int		ampersand;
	int		or_flag;

	while (*command != NULL)
	{
		or_flag = 0;
		ampersand = 0;
		*command = ft_strtrim(*command);
		if (((*command = check_ampersand(*command, &ampersand)) != NULL)
				&& ((or_flag = check_or(*command, or_flag)) != -1))
			ft_treat_cmd(env, *command, ampersand, or_flag);
		command++;
	}
	ft_tabfree(command);
}

int				main(void)
{
	extern char	**environ;
	char		*line;
	char		**split_comma;

	signal(SIGINT, ctrl_c);
	ft_putstr("42sh -> ");
	while (get_next_line(0, &line) == 1)
	{
		line = ft_strtrim(line);
		line = ft_del_tab(line);
		if (ft_error2(line) == 0)
		{
			split_comma = ft_strsplit(line, ';');
			ft_do_comma(split_comma, &environ);
		}
		signal(SIGINT, ctrl_c);
		ft_putstr("42sh -> ");
		free(line);
	}
	if (split_comma)
		ft_tabfree(split_comma);
	return (0);
}
