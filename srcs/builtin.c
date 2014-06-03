/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilbau <mguilbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:26:24 by mguilbau          #+#    #+#             */
/*   Updated: 2014/03/24 18:19:25 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

static void		builtin_exit(char **cmd)
{
	int		i;

	if (cmd[1] == NULL)
		exit(0);
	else if (((i = ft_atoi(cmd[1])) != -1) && (cmd[2] == NULL))
		exit(i);
	else
	{
		ft_putendl("Wrong usage.");
		exit(1);
	}
}

static void		builtin_echo(char **cmd)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (cmd[i] != NULL)
		count += ft_strcount(cmd[i++], '"');
	i = 1;
	if ((count % 2) == 0)
	{
		while (cmd[i] != NULL)
		{
			while (*cmd[i] != '\0')
			{
				if (*cmd[i] != '\0')
					ft_putchar(*cmd[i]);
				cmd[i]++;
			}
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
	else
		ft_putendl("Error. Missing dquote.");
}

int				builtin(char ***env, char **cmd)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
		builtin_exit(cmd);
	if (ft_strcmp(cmd[0], "cd") == 0)
	{
		builtin_cd(env, cmd);
		return (1);
	}
	if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		builtin_setenv(env, cmd);
		return (1);
	}
	if (ft_strcmp(cmd[0], "unsetenv") == 0)
	{
		builtin_unsetenv(env, cmd);
		return (1);
	}
	if (ft_strcmp(cmd[0], "echo") == 0)
	{
		builtin_echo(cmd);
		return (1);
	}
	return (0);
}
