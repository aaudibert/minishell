/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:28:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/24 19:16:24 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		cd_err(char *path)
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
			ft_putendl(path);
			ft_putstr(": Not a directory.");
			return (1);
		}
		ft_putstr(path);
		ft_putendl(": No such file or directory.");
		return (1);
	}
	return (0);
}

int		handle_pwd(t_cpe *cpe, int p, int o)
{
	char *tmp;

	if (ENV[o] && ENV[p])
	{
		tmp = ft_strsub(ENV[p], 3, ft_strlen(ENV[p]));
		free(ENV[o]);
		ENV[o] = ft_strjoin("OLDPWD=", tmp);
		free(tmp);
	}
	return (0);
}

int		check_pwd(t_cpe *cpe)
{
	int i;
	int j;

	i = 0;
	while (ENV[i])
	{
		if (ft_strncmp(ENV[i], "PWD", 3) == 0)
			break ;
		i++;
	}
	j = 0;
	while (ENV[j])
	{
		if (ft_strncmp(ENV[j], "OLDPWD", 6) == 0)
			break ;
		j++;
	}
	if (ft_strcmp(PRM[0], "-") == 0 && !ENV[j])
	{
		ft_putendl(": No such file or directory.");
		return (1);
	}
	return (handle_pwd(cpe, i, j));
}

int		ft_chdir(t_cpe *cpe)
{
	if (PRM[1])
	{
		ft_putendl("cd: Too many arguments.");
		return (1);
	}
	if (cd_err(PRM[0]) && ft_strcmp(PRM[0], "-") != 0)
		return (1);
	check_pwd(cpe);
	return (chdir(PRM[0]));
}
