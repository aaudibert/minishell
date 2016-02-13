/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:04:18 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/13 17:14:31 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		valid_cmd(t_cpe *cpe)
{
	char		**path;
	DIR			*rep;
	t_dirent	*fr;
	int			i;

	i = 0;
	path = ft_strsplit((const char *)cpe->env, ':');
	while (path[i])
	{
		rep = opendir(path[i]);
		while ((fr = readdir(rep)) != NULL)
		{
			if (ft_strcmp(cpe->cmd, fr->d_name) == 0)
			{
				cpe->cmd = ft_strjoin(path[i], cpe->cmd);
				ft_free_arr(path);
				return (0);
			}
		}
		closedir(rep);
		i++;
	}
	ft_free_arr(path);
	return (1);
}
