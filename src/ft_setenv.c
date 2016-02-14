/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:17:50 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/14 19:32:44 by aaudiber         ###   ########.fr       */
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

char		**ft_unsetenv(char **env, char *name)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * ft_arr_size(env));
	//nom de la variable qui erase env
	if (ft_strcmp(name, "") != 0)
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], name, ft_strlen(name)) != 0)
			{
				ret[j] = ft_strdup(env[i]);
				j++;
			}
			i++;
		}
	}
	ft_free_arr(env);
	ret[j] = 0;
	return (ret);
}

char		**ft_initenv(char **env, int init)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * ft_arr_size(env) + 1 + init);
	i = 0;
	while (env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_setenv(char **env, char *name, char *value, int init)
{
	char	**ret;
	int		i;

	i = 0;
	while (env[i])
		i++;
	if (init == 0)
		return (ft_initenv(env, init));
	else
	{
		ret = ft_initenv(env, init);
		ret[i] = ft_strjoin(ft_strjoin(name, "="), value);
		ret[++i] = 0;
		return (ret);
	}
}
