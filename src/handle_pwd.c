/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 19:27:34 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/09 20:52:27 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		handle_pwd(t_cpe *cpe, int p, int o)
{
	char tmp2[PATH_MAX];

	if (ft_strcmp(PRM[0], "-") == 0)
	{
		free(PRM[0]);
		PRM[0] = ft_strdup(OLDPWD);
		if (cd_err(PRM[0]))
			return (1);
		ft_putendl(PRM[0]);
	}
	if (OLDPWD)
		free(OLDPWD);
	getcwd(tmp2, PATH_MAX);
	OLDPWD = ft_strdup(tmp2);
	if (ENV[o] && ENV[p])
	{
		free(ENV[o]);
		ENV[o] = ft_strjoin("OLDPWD=", tmp2);
	}
	return (0);
}

int		check_pwd(t_cpe *cpe)
{
	int i;
	int j;

	i = -1;
	while (ENV[++i])
	{
		if (ft_strncmp(ENV[i], "PWD=", 4) == 0)
			break ;
	}
	j = -1;
	while (ENV[++j])
	{
		if (ft_strncmp(ENV[j], "OLDPWD=", 7) == 0)
			break ;
	}
	if (ft_strcmp(PRM[0], "-") == 0 && !ENV[j] && !OLDPWD && !NENV)
	{
		ft_putendl(": No such file or directory.");
		return (1);
	}
	return (handle_pwd(cpe, i, j));
}

int		new_pwd(t_cpe *cpe)
{
	int		i;
	char	tmp[PATH_MAX];

	i = 0;
	while (ENV[i])
	{
		if (ft_strncmp(ENV[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	getcwd(tmp, PATH_MAX + 1);
	if (ENV[i])
	{
		free(ENV[i]);
		ENV[i] = ft_strjoin("PWD=", tmp);
	}
	return (0);
}
