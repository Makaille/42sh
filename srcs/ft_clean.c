/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:39:41 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/25 11:11:59 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

char		*ft_del_tab(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

char		*ft_del_tilde(char *cmd, char ***env)
{
	char	*home;

	if (cmd[0] == '~')
	{
		home = search_line(env, "HOME=");
		home = ft_strsub(home, 5, ft_strlen(home) - 5);
		cmd = ft_strsub(cmd, 1, ft_strlen(cmd) - 1);
		cmd = ft_strjoin(home, cmd);
		free(home);
	}
	return (cmd);
}

char		**get_clean_arg(char *cmd, char **env)
{
	char	**cmd_arg;
	int		i;

	i = 0;
	cmd_arg = ft_strsplit(cmd, ' ');
	while (cmd_arg[i] != NULL)
		i++;
	if (i > 0)
		cmd_arg[i - 1] = ft_del_tilde(cmd_arg[i - 1], &env);
	return (cmd_arg);
}
