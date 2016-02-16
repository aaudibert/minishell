/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:56:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/16 22:23:18 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*
int			check_var(t_cpe *cpe)
{
	int i;

	i = 0;
	while (PRM[i])
	{
		if ()
	}
	return (arr_size(PRM);
}
*/

//ecrire fct pour verif si prm sont var existantes dans env
//revoir unset et set

int			ft_unsetenv(t_cpe *cpe)
{
	int		i;
	int		j;
	int		u;
	char	**ret;

	i = 0;
	j = 0;
	u = check_var(cpe);
	ret = (char **)malloc(sizeof(char *) * arr_size(ENV) - u);
	while (ENV[i])
	{
		if (ft_strncmp(ENV[i], PRM[u], ft_strlen(PRM[u])) != 0)
		{
			ret[j] = ft_strdup(ENV[i]);
			j++;
		}
		i++;
	}
	ret[j] = 0;
	ft_free_arr(ENV);
	ENV = ret;
	return (0);
}
