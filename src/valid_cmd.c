/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:04:18 by aaudiber          #+#    #+#             */
/*   Updated: 2016/03/08 20:32:59 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		get_cmd(t_cpe *cpe, char **path, int i, DIR *rep)
{
	TCMD = ft_strjoin(ft_strjoin(path[i], "/"), CMD);
	closedir(rep);
	return (0);
}

int		valid_cmd(t_cpe *cpe)
{
	DIR			*rep;
	t_dirent	*fr;
	int			i;

	if (!CMD)
		return (1);
	i = check_builtins(cpe);
	if (i >= 0)
		return (i);
	while (PATH[++i])
	{
		rep = opendir(PATH[i]);
		while (rep == NULL && PATH[i])
			rep = opendir(PATH[++i]);
		if (!PATH[i])
			break ;
		while ((fr = readdir(rep)) != NULL)
		{
			if (ft_strcmp(CMD, fr->d_name) == 0)
				return (get_cmd(cpe, PATH, i, rep));
		}
		closedir(rep);
	}
	g_ex = 0;
	ft_putjoin(CMD, ": Command not found.");
	return (1);
}
