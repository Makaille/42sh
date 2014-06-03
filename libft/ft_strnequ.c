/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:06:29 by ysoto             #+#    #+#             */
/*   Updated: 2014/02/12 15:30:44 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = ft_strncmp(s1, s2, n);
	if (i == 0)
		return (1);
	return (0);
}
