/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:07:27 by ysoto             #+#    #+#             */
/*   Updated: 2013/12/17 10:20:49 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;

	l2 = ft_strlen(s2);
	if (!l2)
		return (char *)s1;
	l1 = ft_strlen(s1);
	while (l1 >= l2)
	{
		l1--;
		if (!ft_memcmp(s1, s2, l2))
			return (char *)s1;
		s1++;
	}
	return (NULL);
}
