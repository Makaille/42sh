/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:50:22 by ysoto             #+#    #+#             */
/*   Updated: 2014/02/27 18:09:35 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
