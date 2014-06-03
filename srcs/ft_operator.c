/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:51:10 by fperret           #+#    #+#             */
/*   Updated: 2014/03/26 13:27:53 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

void	split_exec_ampersand(char ***env, char *command, int *execve_flag)
{
	char	**split_ampersand;

	split_ampersand = ft_strsplit(command, '&');
	while (*split_ampersand != NULL)
	{
		ft_launch_exec(*split_ampersand, env, execve_flag);
		if (*execve_flag != 0 && *execve_flag != -1)
		{
			ft_tabfree(split_ampersand);
			break ;
		}
		split_ampersand++;
	}
}

int		ampersand_and_or(char ***env, char *command, int *execve_flag)
{
	char		**split_or;

	split_or = ft_strsplit_index(command, '|');
	while (*split_or != NULL)
	{
		if (ft_strsrch2(*split_or, '&') == 42)
			split_exec_ampersand(env, *split_or, execve_flag);
		else
			ft_launch_exec(*split_or, env, execve_flag);
		if (*execve_flag == 0)
		{
			ft_tabfree(split_or);
			*execve_flag = -1;
			break ;
		}
		split_or++;
	}
	return (1);
}

void	no_ampersand_and_or(char ***env, char *command, int *execve_flag)
{
	char		**split_or;

	split_or = ft_strsplit_index(command, '|');
	while (*split_or != NULL)
	{
		*execve_flag = -1;
		ft_launch_exec(*split_or, env, execve_flag);
		if (*execve_flag == 0)
		{
			ft_tabfree(split_or);
			break ;
		}
		split_or++;
	}
}

char	*check_ampersand(char *string, int *flag)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * (count_char_double(string, '&')));
	while (string[i] != '\0')
	{
		if ((string[i] == '&') && (string[i + 1] == '&'))
		{
			if (string[i + 2] == '&')
			{
				ft_putendl("Parse error near `&'.");
				return (NULL);
			}
			*flag = 1;
			i++;
		}
		dest[j] = string[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int		check_or(char *string, int flag)
{
	int		i;

	i = 0;
	if (ft_strstr(string, ">>>") != NULL || ft_strstr(string, "<<<") != NULL)
	{
		ft_putendl("Missing name for redirect.");
		return (-1);
	}
	while (string[i] != '\0')
	{
		if ((string[i] == '|') && (string[i + 1] == '|'))
		{
			if (string[i + 2] == '|')
			{
				ft_putendl("Parse error near `|'");
				return (-1);
			}
			flag = 1;
		}
		i++;
	}
	return (flag);
}
