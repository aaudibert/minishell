/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:17:50 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/18 17:27:02 by aaudiber         ###   ########.fr       */
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

	ret = (char **)malloc(sizeof(char *) * arr_size(env) + 1 + init);
	i = 0;
	while (env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int			ft_setenv(t_cpe *cpe, char *name, char *value)
{
	int i;

	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '=')
		{
			ft_putendl("new env name cannot contain '='");
			return (1);
		}
		i++;
	}
	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] == '=')
		{
			ft_putendl("new env value cannot contain '='");
			return (1);
		}
		i++;
	}
	ENV = ft_initenv(ENV, 1);
	ENV[arr_size(ENV) + 1] = ft_strjoin(ft_strjoin(name, "="), value);
	return (0);
}
