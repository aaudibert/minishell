/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 16:40:11 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/10 19:52:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			lenc(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char		*ft_trimc(char *str, char c)
{
	int			i;
	char		*ret;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	ret = ft_strsub(str, 0, i);
	ret[i] = '\0';
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	char			*buf;
	static char		*s = "";
	int				i;
	int				result;

	if (!line)
		return (-1);
	buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	while (!ft_strchr(s, '\n'))
	{
		i = read(fd, buf, BUFF_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		s = ft_strjoin(s, buf);
	}
	*line = ft_trimc(s, '\n');
	result = ft_strlen(s);
	s = ft_strsub(s, (lenc(s, '\n') + 1), (ft_strlen(s) - lenc(s, '\n') + 1));
	free(buf);
	if (i < 0)
		return (-1);
	if ((result == 0) && i == 0)
		return (0);
	return (1);
}
