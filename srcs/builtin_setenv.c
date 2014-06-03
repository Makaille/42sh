/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilbau <mguilbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:31:47 by mguilbau          #+#    #+#             */
/*   Updated: 2014/03/25 11:09:37 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			builtin_setenv(char ***env, char **cmd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (error_setenv(cmd) == 1)
	{
		cmd[1] = ft_strjoin(cmd[1], "=");
		if (cmd[2] != NULL)
			tmp = ft_strjoin(cmd[1], cmd[2]);
		else
			tmp = ft_strdup(cmd[1]);
		if ((j = search_num_line(env, cmd[1])) != -1)
			(*env)[j] = ft_strdup(tmp);
		else
		{
			*env = ft_tab_dup(*env);
			while ((*env)[i] != NULL)
				i++;
			(*env)[i] = ft_strdup(tmp);
		}
	}
}
