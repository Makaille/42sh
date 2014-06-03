/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fperret <fperret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 10:35:06 by fperret           #+#    #+#             */
/*   Updated: 2014/03/25 11:19:57 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_rd(char *command, char ***env, int *execve_flag)
{
	if (exec_redi_left(command, env, execve_flag) == 0)
		return (0);
	if (exec_doublerd(command, env, execve_flag) == 0)
		return (0);
	else if (exec_redi_right(command, env, execve_flag) == 0)
		return (0);
	return (1);
}
