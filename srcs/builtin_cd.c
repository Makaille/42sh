/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilbau <mguilbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:31:56 by mguilbau          #+#    #+#             */
/*   Updated: 2014/03/25 11:03:34 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

static int		ft_update_env(char ***env)
{
	int		num;
	char	*tmp;
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	tmp = "";
	if ((num = search_num_line(env, "OLDPWD=")) != -1)
		(*env)[num] = ft_strjoin("OLD", search_line(env, "PWD="));
	if ((num = search_num_line(env, "PWD=")) != -1)
	{
		(*env)[num] = ft_strjoin(tmp, "PWD=");
		(*env)[num] = ft_strjoin((*env)[num], pwd);
	}
	free(pwd);
	return (1);
}

static void		cd_home(char ***env, char *tmp)
{
	int		i;

	i = 0;
	if ((tmp = search_line(env, "HOME=")) != NULL)
	{
		tmp = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
		chdir(tmp);
		ft_update_env(env);
	}
}

static void		cd_minus(char ***env, char *tmp)
{
	if ((tmp = search_line(env, "OLDPWD=")) != NULL)
	{
		tmp = ft_strsub(tmp, 7, ft_strlen(tmp) - 7);
		chdir(tmp);
		ft_update_env(env);
		tmp = NULL;
		ft_putendl(getcwd(tmp, 0));
	}
}

static void		cd_path(char ***env, char *tmp)
{
	if (chdir(tmp) == -1)
	{
		ft_putstr("42sh : no such file or directory: ");
		ft_putendl(tmp);
	}
	else
		ft_update_env(env);
}

void			builtin_cd(char ***env, char **cmd)
{
	char	*tmp;

	tmp = NULL;
	if (cmd[1] == NULL || (ft_strcmp(cmd[1], "~") == 0))
		cd_home(env, tmp);
	else if (ft_strcmp(cmd[1], "-") == 0)
		cd_minus(env, tmp);
	else
	{
		tmp = cmd[1];
		cd_path(env, tmp);
	}
}
