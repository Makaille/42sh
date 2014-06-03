/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:15:04 by fperret           #+#    #+#             */
/*   Updated: 2014/03/27 10:04:35 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		give_start(char const *s, int i)
{
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		beginning;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	beginning = give_start(s, 0);
	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	len = i;
	if ((len - beginning) < 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len - beginning + 2));
	if (str == NULL)
		return (NULL);
	str = ft_strsub(s, beginning, len - beginning + 1);
	str[len - beginning + 1] = '\0';
	return (str);
}
