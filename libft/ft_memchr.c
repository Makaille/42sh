/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:58:42 by ysoto             #+#    #+#             */
/*   Updated: 2013/12/01 14:18:47 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		tmp_c;
	char		*tmp_s;

	tmp_c = (unsigned char)c;
	tmp_s = (char*)s;
	while (n--)
	{
		if (*tmp_s == tmp_c)
			return (tmp_s);
		tmp_s++;
	}
	return (NULL);
}
