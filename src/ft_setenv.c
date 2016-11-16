/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:17:50 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/14 17:49:01 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			err_check(t_cpe *cpe)
{
	int i;

	i = 0;
	while (PRM[0][i] != '\0')
	{
		if (PRM[0][i] == '=')
		{
			ft_putendl("new env name cannot contain '='");
			return (1);
		}
		i++;
	}
	i = 0;
	if (!PRM[1])
		return (0);
	while (PRM[1][i])
	{
		if (PRM[1][i] == '=')
		{
			ft_putendl("new env value cannot contain '='");
			return (1);
		}
		i++;
	}
	return (valid_env(PRM[0]));
}

int			new_env_val(t_cpe *cpe, int i)
{
	char	*tmp;

	tmp = ft_strjoin(PRM[0], "=");
	if (!ft_strcmp(PRM[0], "OLDPWD"))
	{
		free(OLDPWD);
		OLDPWD = ft_strdup(PRM[1]);
	}
	ENV[i] = ft_strjoin(tmp, PRM[1]);
	free(tmp);
	return (0);
}

int			re_setenv(t_cpe *cpe, int i)
{
	char	*tmp;

	while (ENV[i])
	{
		if (ft_strncmp(ENV[i], PRM[0], ft_strlen(PRM[0])) == 0 &&
				ENV[i][ft_strlen(PRM[0])] == '=')
		{
			free(ENV[i]);
			if (arr_size(PRM) == 2)
				return (new_env_val(cpe, i));
			else
			{
				tmp = ft_strjoin(PRM[0], "=");
				ENV[i] = tmp;
				return (0);
			}
		}
		i++;
	}
	return (-1);
}

int			ft_setenv(t_cpe *cpe)
{
	int		i;
	char	*tmp;

	i = 0;
	if (err_check(cpe) == 1)
		return (1);
	i = re_setenv(cpe, 0);
	if (i == 1 || i == 0)
		return (i);
	ENV = ft_initenv(ENV, 1, cpe);
	if (arr_size(PRM) == 2)
	{
		i = arr_size(ENV) - 1;
		tmp = ft_strjoin(ENV[i], PRM[1]);
		free(ENV[i]);
		ENV[i] = tmp;
	}
	return (0);
}
