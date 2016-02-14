/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:04:18 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/14 20:06:38 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		valid_cmd(t_cpe *cpe)
{
	char		**path;
	DIR			*rep;
	t_dirent	*fr;
	int			i;
	char *tmp;

	i = 0;
	tmp = get_path(cpe->env);
	ft_putendl(tmp);
	ft_putendl("--------------------------------------------------------------------------------");
	path = ft_strsplit(/*get_path(cpe->env)*/tmp, ':');
	print_arr(cpe->env);
	ft_putendl("--------------------------------------------------------------------------------");
	print_arr(path);
	if (!cpe->cmd)
		return (1);
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
	ft_putendl("eokneroierqjhnierqhlq");
	if (path)
		ft_free_arr(path);
	ft_putendl("eokneroierqjhnierqhlq");
	return (1);
}
