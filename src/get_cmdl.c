/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 19:36:12 by aaudiber          #+#    #+#             */
/*   Updated: 2016/10/26 20:02:54 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		get_cmdl(char *line)
{
	char	*buf;
	int		i;

	i = 0;
	while (line[i - 1] != '\n')
	{
		buf = (char *)malloc(sizeof(char) * 2);
		buf[1] = 0;
		if (read(0, buf, 1) == 0)
			return (0);
		if (buf[0] != '\n')
			line[i] = buf[0];
		else
			break ;
		i++;
		free(buf);
	}
	free(buf);
	return (1);
}
