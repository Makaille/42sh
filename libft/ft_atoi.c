/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:10:50 by fperret           #+#    #+#             */
/*   Updated: 2014/03/02 16:56:52 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		negative;

	result = 0;
	negative = 1;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	if (*str == '+')
		str++;
	if (check_digit(str) == 0)
		return (-1);
	while (ft_isdigit(*str) && str)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * negative);
}
