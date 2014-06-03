/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 20:20:01 by mroux             #+#    #+#             */
/*   Updated: 2014/03/27 10:21:06 by mvallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_my_realloc(char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			j;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	substr[len] = '\0';
	if (substr == NULL || !s)
		return (NULL);
	j = 0;
	while (j < len)
	{
		substr[j] = s[start];
		j++;
		start++;
	}
	free(s);
	return (substr);
}

static int	if_mini(char **mini, char **line, int *i)
{
	char			*j;
	unsigned int	k;

	if (!(j = ft_strchr(*mini, '\n')))
	{
		*i = *i + ft_strlen(*mini);
		*line = ft_my_realloc(*line, 0, *i);
		ft_strncat(*line, *mini, ft_strlen(*mini));
		*mini = ft_strnew(0);
	}
	else
	{
		k = j - *mini;
		*i = *i + k;
		*line = ft_my_realloc(*line, 0, *i);
		ft_strncat(*line, *mini, k);
		*mini = *mini + k + 1;
		return (1);
	}
	return (0);
}

static int	if_no_mini(char **buff, char **line, int *i, char **mini)
{
	char			*j;
	unsigned int	k;

	if (!(j = ft_strchr(*buff, '\n')))
	{
		*i = *i + BUFF_SIZE;
		*line = ft_my_realloc(*line, 0, *i);
		ft_strncat(*line, *buff, BUFF_SIZE);
	}
	else
	{
		k = j - *buff;
		*i = *i + k;
		*line = ft_my_realloc(*line, 0, *i);
		ft_strncat(*line, *buff, k);
		*mini = ft_strsub(*buff, k + 1, BUFF_SIZE - k - 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char			*buff;
	int				i;
	int				m;
	static char		*mini = "\0";

	i = 0;
	m = 1;
	*line = (char *)malloc(sizeof(char) * 1);
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (line == NULL || fd < 0 || *line == NULL || buff == NULL)
		return (-1);
	**line = '\0';
	while (m != 0)
	{
		if (*mini && if_mini(&mini, line, &i) == 1)
			return (1);
		m = read(fd, buff, BUFF_SIZE);
		if (!(*mini) && m && (buff[m] = 0) == 0)
			if (if_no_mini(&buff, line, &i, &mini) == 1)
				return (1);
	}
	if (**line)
		return (1);
	return (0);
}
