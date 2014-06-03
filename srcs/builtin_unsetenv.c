/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:03:47 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/25 11:11:06 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		**ft_unsetenv(char **env, char *cmd)
{
	char	**tab;
	int		i;

	cmd = ft_strjoin(cmd, "=");
	i = search_num_line(&env, cmd);
	if (i != -1)
	{
		tab = ft_tab_rep(env, cmd);
		return (tab);
	}
	else
		return (env);
}

void			builtin_unsetenv(char ***env, char **cmd)
{
	int		i;

	i = 1;
	if (error_unsetenv(cmd) == 0)
	{
		while (cmd[i] != NULL)
		{
			*env = ft_unsetenv(*env, cmd[i]);
			i++;
		}
	}
}
