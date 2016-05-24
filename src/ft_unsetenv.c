/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:56:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/24 21:56:07 by aaudiber         ###   ########.fr       */
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
			if (ft_strncmp(PRM[i], ENV[j], ft_strlen(PRM[i])) == 0 &&
					ENV[j][ft_strlen(PRM[i])])
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
	/*if (!ENV[i])
		return (0);
	while (PRM[j])
	{
		if (ft_strncmp(PRM[j], ENV[i], ft_strlen(PRM[j])) == 0 &&
				ENV[i][ft_strlen(PRM[j])] == '=')
		{
			if (!ft_strcmp(PRM[j], "OLDPWD"))
			{
				free(OLDPWD);
				OLDPWD = NULL;
			}
			return (1);
		}
		j++;
	}
	return (0);*/
	if (!ENV[i])
		return (i);
	while (PRM[j])
	{
		if (ft_strncmp(PRM[j], ENV[i], ft_strlen(PRM[j])) == 0 &&
				ENV[i][ft_strlen(PRM[j])] == '=')
			return (1);
		j++;
	}
	return (0);
}

char		**ft_unset(t_cpe *cpe)
{
	int		i;
	int		j;
	char	**rt;

	i = 0;
	j = -1;
	rt = (char **)malloc(sizeof(char *) * (arr_size(ENV) - check_var(cpe) + 1));
	while (ENV[i])
	{
		/*while (skip_var(cpe, i))
			i++;*/
		i = i + skip_var(cpe, i);
		if (ENV[i])
		{
			rt[++j] = ft_strdup(ENV[i]);
		}
		else
			break ;
		i++;
	}
	rt[++j] = 0;
	return (rt);
}

int			ft_unsetenv(t_cpe *cpe)
{
	char	**rt;

	if (!PRM)
	{
		ft_putendl("unsetenv: Too few arguments");
		return (1);
	}
	if (!check_var(cpe))
		return (1);
	if (ENV[1])
	{
		rt = ft_unset(cpe);
		ft_putendl("ijdvijve");
		ft_free_arr(ENV);
		ft_putendl("ijdvijve");
		ENV = rt;
	}
	else
		ENV[0] = 0;
	return (0);
}
