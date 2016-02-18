/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:56:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/18 17:25:26 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		ft_unprm(t_cpe *cpe, int u)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * arr_size(ENV) - 1);
	while (ENV[i])
	{
		if (i == u)
			i++;
		ret[j] = ft_strdup(ENV[i]);
		i++;
		j++;
	}
	ft_free_arr(ENV);
	ENV = ret;
}

int			check_var(t_cpe *cpe)
{
	int i;
	int u;
	int ret;

	i = 0;
	u = 0;
	ret = 0;
	while (PRM[u])
	{
		while (ENV[i])
		{
			if (ft_strncmp(ENV[i], PRM[u], ft_strlen(PRM[u])) == 0)
				ret++;
			i++;
		}
		if (i == arr_size(ENV))
			ft_unprm(cpe, u);
		i = 0;
		u++;
	}
	return (ret);
}

int			ft_unsetenv(t_cpe *cpe)
{
	int		i;
	int		j;
	int		u;
	char	**ret;

	i = 0;
	j = -1;
	u = check_var(cpe);
	ret = (char **)malloc(sizeof(char *) * arr_size(ENV) - u);
	while (PRM[u])
	{
		while (ENV[i])
		{
			if (ft_strncmp(ENV[i], PRM[u], ft_strlen(PRM[u])) != 0)
				ret[++j] = ft_strdup(ENV[i]);
			i++;
		}
		i = 0;
		u++;
	}
	ret[j] = 0;
	ft_free_arr(ENV);
	ENV = ret;
	return (0);
}
