/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 10:05:24 by fperret           #+#    #+#             */
/*   Updated: 2014/03/27 10:06:14 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_tab(char **src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char			**ft_tab_dup(char **src)
{
	char		**tab;
	int			i;

	i = ft_count_tab(src);
	tab = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (src[i] != NULL)
	{
		tab[i] = ft_strdup(src[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_tab_rep(char **src, char *str)
{
	char		**tab;
	int			j;
	int			k;

	k = ft_count_tab(src);
	tab = (char **)malloc(sizeof(char *) * (k - 1 + 1));
	k = 0;
	j = 0;
	while (src[k] != NULL)
	{
		if (ft_strncmp(src[k], str, ft_strlen(str)) != 0)
		{
			tab[j] = ft_strdup(src[k]);
			j++;
			k++;
		}
		else
			k++;
	}
	tab[j] = NULL;
	return (tab);
}
