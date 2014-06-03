/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:24:41 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/27 10:13:52 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (i < len)
	{
		tmp[i] = (char)c;
		i++;
	}
	return (s);
}
