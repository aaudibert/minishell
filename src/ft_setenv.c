/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:17:50 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/12 16:35:11 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**ft_initenv(char **env, int init)
{
	int		i;
	char	**ret;

	i = 0;
	while (env[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * i + 1 + init);
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
