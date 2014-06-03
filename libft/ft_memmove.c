/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:13:49 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/27 10:17:37 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*tmpd;
	char	*tmps;
	char	ptr[n];

	tmpd = (char *)s1;
	tmps = (char *)s2;
	i = 0;
	while (i < n)
	{
		ptr[i] = tmps[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmpd[i] = ptr[i];
		i++;
	}
	return (tmpd);
}
