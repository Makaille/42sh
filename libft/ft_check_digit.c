/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 10:33:55 by fperret           #+#    #+#             */
/*   Updated: 2014/03/02 16:59:20 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_digit(const char *str)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(str) - 1) && ft_isdigit(str[i]))
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	else
		return (1);
}
