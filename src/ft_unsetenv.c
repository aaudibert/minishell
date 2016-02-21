/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:56:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/21 17:26:21 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			check_var(t_cpe *cpe)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	ret = 0;
	while (PRM[i])
	{
		if (PRM[i][ft_strlen(PRM[i]) - 1] == '=')
			i++;
		if (!PRM[i])
			break ;
		while (ENV[j])
		{
			if (ft_strncmp(PRM[i], ENV[j], ft_strlen(PRM[i])) == 0)
				ret++;
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}

int			skip_var(t_cpe *cpe, int i)
{
	int j;

	j = 0;
	while (PRM[j])
	{
		if (ft_strncmp(PRM[j], ENV[i], ft_strlen(PRM[j])) == 0)
			return (1);
		j++;
	}
	return (0);
}


char		**ft_unset(t_cpe *cpe)
{
	int		i;
	int		j;
	int		u;
	char	**rt;

	i = 0;
	j = -1;
	u = 0;
	rt = (char **)malloc(sizeof(char *) * (arr_size(ENV) - check_var(cpe) + 1));
	while (ENV[i])
	{
		while (skip_var(cpe, i))
			i++;
		rt[++j] = ft_strdup(ENV[i]);
		i++;
	}
	return (rt);
}

int			ft_unsetenv(t_cpe *cpe)
{
	char	**rt;

	if (!PRM || !check_var(cpe))
		return (1);
	rt = ft_unset(cpe);
	rt[arr_size(rt)] = 0;
	ft_free_arr(ENV);
	ENV = rt;
	return (0);
}
