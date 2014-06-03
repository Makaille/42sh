/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:37:00 by fperret           #+#    #+#             */
/*   Updated: 2014/03/26 13:44:22 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>

int		*call_pipe(int *pi)
{
	if (pipe(pi) == -1)
	{
		ft_putendl("Pipe error.");
		return (NULL);
	}
	return (pi);
}

void	ft_fork_error(int *pi)
{
	close(pi[0]);
	close(pi[1]);
	exit(1);
}

void	ft_error_redi(char *str)
{
	if (access(str, F_OK) == -1)
	{
		ft_putstr("42sh: no such file or directory: ");
		ft_putendl(str);
	}
	else
	{
		ft_putstr(str);
		ft_putendl(": Permission denied");
	}
}
