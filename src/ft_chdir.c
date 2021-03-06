/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:28:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/08/11 18:09:49 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			cd_err(char *path)
{
	t_stat		sb;

	stat(path, &sb);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		if (access(path, R_OK) == -1)
		{
			ft_putstr(path);
			ft_putendl(": Permission denied.");
			return (1);
		}
	}
	else
	{
		if ((sb.st_mode & S_IFMT) != S_IFDIR && access(path, F_OK) == 0)
		{
			ft_putstr(path);
			ft_putendl(": Not a directory.");
			return (1);
		}
		ft_putstr(path);
		ft_putendl(": No such file or directory.");
		return (1);
	}
	return (0);
}

void		home_path(t_cpe *cpe)
{
	if (!PRM)
	{
		PRM = (char **)malloc(sizeof(char *) * 2);
		PRM[1] = 0;
	}
	else
		free(PRM[0]);
	PRM[0] = ft_strdup(HOME);
}

int			ft_chdir(t_cpe *cpe)
{
	if (!HOME && (!PRM || ft_strcmp(PRM[0], "~") == 0 ||
				ft_strcmp(PRM[0], "$HOME") == 0))
	{
		ft_putendl("No $home variable set");
		return (1);
	}
	else if (HOME != NULL && (!PRM || ft_strcmp(PRM[0], "~") == 0 ||
				ft_strcmp(PRM[0], "$HOME") == 0))
		home_path(cpe);
	if (PRM[1])
	{
		ft_putendl("cd: Too many arguments.");
		return (1);
	}
	if (ft_strcmp(PRM[0], "-") != 0)
	{
		if (cd_err(PRM[0]))
			return (1);
	}
	if (check_pwd(cpe))
		return (1);
	chdir(PRM[0]);
	return (new_pwd(cpe));
}
