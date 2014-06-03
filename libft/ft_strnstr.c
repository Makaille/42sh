/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:44:19 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/27 10:02:44 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && n > 0)
	{
		while ((s1[i] == s2[j]) && (s1[i] != '\0') && (n > 0))
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i - (j - 1)]);
			n--;
			if (s1[i++] == s2[j])
				i++;
			if (s1[i] != s2[j])
				j = 0;
		}
		i++;
		n--;
	}
	return (NULL);
}
