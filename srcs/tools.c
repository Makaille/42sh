/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 14:55:11 by fperret           #+#    #+#             */
/*   Updated: 2014/03/25 11:24:09 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		search_num_line(char ***env, char *sch)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(sch);
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], sch, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*search_line(char ***env, char *sch)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(sch);
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], sch, len) == 0)
			return ((*env)[i]);
		i++;
	}
	return (NULL);
}

int		count_char_double(char *string, char c)
{
	int		i;
	int		count;
	int		ret;

	count = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if ((string[i] == c) && (string[i + 1] == c))
			count++;
		i++;
	}
	i++;
	ret = i - count;
	return (ret);
}

int		ft_check_redi(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>')
		{
			i++;
			if (str[i] == '>')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (-1);
}
