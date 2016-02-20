/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:17:50 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/20 20:51:38 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		ft_print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

char		**ft_initenv(char **env, int init)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (arr_size(env) + 1 + init));
	i = 0;
	while (env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	if (i == 1)
		ft_free_arr(env);
	if (init == 0)
		ret[i] = 0;
	return (ret);
}

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
	return (0);
}

int			re_setenv(t_cpe *cpe)
{
	int i;

	i = 0;
	while (ENV[i])
	{
		if (ft_strncmp(ENV[i], PRM[0], ft_strlen(PRM[0])) == 0)
		{
			if (PRM[1])
			{
				free(ENV[i]);
				ENV[i] = ft_strjoin(ft_strjoin(PRM[0], "="), PRM[1]);
				return (0);
			}
			else
				return (1);
		}
		i++;
	}
	return (-1);
}

int			ft_setenv(t_cpe *cpe)
{
	int i;

	i = 0;
	if (err_check(cpe) == 1)
		return (1);
	i = re_setenv(cpe);
	if (i == 1 || i == 0)
		return (i);
	ENV = ft_initenv(ENV, 1);
	if (PRM[1])
		ENV[arr_size(ENV)] = ft_strjoin(ft_strjoin(PRM[0], "="), PRM[1]);
	else
		ENV[arr_size(ENV)] = ft_strjoin(PRM[0], "=");
	ENV[arr_size(ENV)] = 0;
	return (0);
}
