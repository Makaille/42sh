/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilbau <mguilbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:13:31 by mguilbau          #+#    #+#             */
/*   Updated: 2014/03/26 16:50:29 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_error(char *cmd)
{
	if (cmd != NULL)
	{
		if (ft_strchr(cmd, '/'))
			ft_putstr("42sh: no such file or directory: ");
		else
			ft_putstr("42sh: command not found: ");
		ft_putendl(cmd);
	}
}

int		error_unsetenv(char **cmd)
{
	if (cmd[1] == NULL)
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (1);
	}
	return (0);
}

int		error_setenv(char **cmd)
{
	if (((ft_strsrch(cmd[1], '=') != -1)) || (ft_strsrch(cmd[1], '=') == -2))
	{
		ft_putendl("setenv: Syntax Error.");
		return (0);
	}
	else if (cmd[3] != NULL)
	{
		ft_putendl("setenv: Too many arguments");
		return (0);
	}
	else
		return (1);
}

int		ft_error2(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == ';' && cmd[i + 1] == ';')
		{
			ft_putendl("42sh: parse error near ';;'");
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_error_null_command(char *command)
{
	int		i;
	char	**split;

	split = ft_strsplit(command, ' ');
	i = 0;
	if (command[i] == '<' && (access(split[1], F_OK) == -1))
		return (1);
	if (command[i] == '>')
		return (1);
	while (command[i] != '\0')
		i++;
	i--;
	if (command[i] == '|')
		return (1);
	else
		return (0);
}
