/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:05:10 by fperret           #+#    #+#             */
/*   Updated: 2014/03/16 14:29:48 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsrch2(char *str, char c)
{
	int		i;
	int		ret;

	if (str == NULL)
		return (-2);
	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c)
			ret = 42;
	}
	return (ret);
}

int		ft_strsrch(char *str, char c)
{
	int		i;

	if (str == NULL)
		return (-2);
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}
