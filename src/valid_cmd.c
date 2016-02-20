/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:04:18 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/20 16:34:42 by aaudiber         ###   ########.fr       */
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

	if (!CMD)
		return (1);
	i = check_builtins(cpe);
	if (i >= 0)
		return (i);
	while (path[++i])
	{
		rep = opendir(path[i]);
		while (rep == NULL && path[i])
			rep = opendir(path[++i]);
		if (!path[i])
			break ;
		while ((fr = readdir(rep)) != NULL)
		{
			if (ft_strcmp(CMD, fr->d_name) == 0)
				return (get_cmd(cpe, path, i, rep));
		}
		closedir(rep);
	}
	ft_free_arr(path);
	return (1);
}
