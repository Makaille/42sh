/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 14:58:09 by fperret           #+#    #+#             */
/*   Updated: 2014/03/25 11:22:23 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

static void			get_char_index(char *s, char c, t_split *tab_split)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab_split->tab_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] == c)
			tab_split->tab_size++;
		i++;
	}
	tab_split->tab = (int *)malloc(sizeof(int) * (tab_split->tab_size));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] == c)
		{
			tab_split->tab[j] = i;
			s[i + 1] = ' ';
			j++;
		}
		i++;
	}
}

static char			**ft_split(t_split *tab_split, char **split, char *s, int i)
{
	int		start;
	int		j;

	j = 0;
	start = 0;
	while (s[i])
	{
		if (i == tab_split->tab[j])
			i++;
		else
		{
			start = i;
			if (start != 0 && i != 1)
				start++;
			else if (i == 1)
				start--;
			while (s[i] && i != tab_split->tab[j])
				i++;
			split[j++] = ft_strsub(s, start, (i - start));
			split[j - 1] = ft_strtrim(split[j - 1]);
		}
	}
	split[j] = NULL;
	return (split);
}

char				**ft_strsplit_index(char *s, char c)
{
	char		**split;
	int			i;
	t_split		*tab_split;

	tab_split = (t_split *)malloc(sizeof(t_split));
	get_char_index(s, c, tab_split);
	if (!(split = (char **)malloc(sizeof(char *) * (tab_split->tab_size + 2))))
		return (NULL);
	i = 0;
	split = ft_split(tab_split, split, s, i);
	return (split);
}
