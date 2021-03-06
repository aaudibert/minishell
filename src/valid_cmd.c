/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:04:18 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/17 20:47:16 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			err_cmd(t_cpe *cpe)
{
	if (access(CMD, X_OK) == 0)
	{
		TCMD = ft_strdup(CMD);
		return (0);
	}
	if (!TCMD)
		ft_putjoin(CMD, ": Command not found.");
	else
		ft_putjoin(TCMD, ": Command not found.");
	return (1);
}

int			get_cmd(t_cpe *cpe, char **path, int i, DIR *rep)
{
	char *tmp;

	if (access(CMD, X_OK) == 0)
		TCMD = ft_strdup(CMD);
	else if (access(TCMD, X_OK) != 0)
	{
		tmp = ft_strjoin(path[i], "/");
		TCMD = ft_strjoin(tmp, CMD);
		free(tmp);
	}
	closedir(rep);
	return (0);
}

int			valid_cmd(t_cpe *cpe, int ac)
{
	DIR			*rep;
	t_dirent	*fr;
	int			i;

	if (!CMD)
		return (ac);
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
			if (ft_strcmp(CMD, fr->d_name) == 0 || !ft_strncmp(CMD, "./", 2))
				return (get_cmd(cpe, PATH, i, rep));
		}
		closedir(rep);
	}
	return (err_cmd(cpe));
}
