/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:41:00 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/27 09:58:26 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*tmp_dest;
	char			*tmp_src;

	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	i = 0;
	while (i < n)
	{
		if (tmp_src[i] == c)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
			return (tmp_dest + i);
		}
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (NULL);
}
