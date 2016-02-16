/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:04:18 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/16 21:42:25 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		get_cmd(t_cpe *cpe, char **path, int i, DIR *rep)
{
	TCMD = ft_strjoin(ft_strjoin(path[i], "/") , CMD);
	closedir(rep);
	ft_free_arr(path);
	return (0);
}

int		valid_cmd(t_cpe *cpe, char **path)
{
	DIR			*rep;
	t_dirent	*fr;
	int			i;

	i = 0;
	if (!cpe->cmd)
		return (1);
	while (path[i])
	{
		rep = opendir(path[i]);
		while (rep == NULL && path[i])
			rep = opendir(path[++i]);
		if (!path[i])
			break ;
		while ((fr = readdir(rep)) != NULL)
		{
			if (ft_strcmp(cpe->cmd, fr->d_name) == 0)
				return (get_cmd(cpe, path, i, rep));
		}
		closedir(rep);
		i++;
	}
	ft_free_arr(path);
	return (1);
}
