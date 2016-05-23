/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 19:27:34 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/23 19:28:53 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		handle_pwd(t_cpe *cpe, int p, int o)
{
	char *tmp;

	if (ft_strcmp(PRM[0], "-") == 0)
	{
		free(PRM[0]);
		PRM[0] = get_name(ENV, "OLDPWD=", 7);
		ft_putendl(PRM[0]);
	}
	if (ENV[o] && ENV[p])
	{
		tmp = get_name(ENV, "PWD=", 4);
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

int		new_pwd(t_cpe *cpe)
{
	int		i;
	char	tmp[PATH_MAX];

	i = 0;
	while (ENV[i])
	{
		if (ft_strncmp(ENV[i], "PWD", 3) == 0)
			break ;
		i++;
	}
	getcwd(tmp, PATH_MAX + 1);
	free(ENV[i]);
	ENV[i] = ft_strjoin("PWD=", tmp);
	return (0);
}
