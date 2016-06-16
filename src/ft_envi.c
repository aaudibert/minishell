/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 21:40:27 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/10 18:04:17 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		env_nopt(t_cpe *cpe)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	j = 0;
	CMD = ft_strdup(PRM[0]);
	TPRM[0] = ft_strdup(CMD);
	tmp = (char **)malloc(sizeof(char *) * (arr_size(PRM)));
	while (PRM[i])
	{
		tmp[j] = ft_strdup(PRM[i]);
		TPRM[i] = ft_strdup(PRM[i]);
		i++;
		j++;
	}
	TPRM[i] = 0;
	tmp[j] = 0;
	ft_free_arr(PRM);
	PRM = tmp;
	return (check_builtins(cpe));
}

int		env_i(t_cpe *cpe)
{
	int		i;
	int		j;
	char	**tmp;

	i = 2;
	j = 0;
	CMD = ft_strdup(PRM[1]);
	TPRM[0] = ft_strdup(CMD);
	tmp = (char **)malloc(sizeof(char *) * (arr_size(PRM) - 1));
	while (PRM[i])
	{
		tmp[j] = ft_strdup(PRM[i]);
		TPRM[j + 1] = ft_strdup(PRM[i]);
		i++;
		j++;
	}
	TPRM[j + 1] = 0;
	tmp[j] = 0;
	ft_free_arr(PRM);
	PRM = tmp;
	NENV = 1;
	return (check_builtins(cpe));
}

int		check_envi(t_cpe *cpe)
{
	int i;
	int j;

	if (!PRM)
		return (print_arr(ENV) + 10);
	if ((ft_strcmp(PRM[0], "-i") == 0 && (ft_strcmp("setenv", PRM[1]) == 0 ||
					ft_strcmp(PRM[1], "unsetenv") == 0)) || ft_strcmp("setenv",
				PRM[0]) == 0 || ft_strcmp(PRM[0], "unsetenv") == 0)
		return (10);
	if (ft_strcmp(PRM[0], "-i") == 0)
		i = 1;
	else
		i = 0;
	j = arr_size(TPRM);
	free(CMD);
	ft_free_arr(TPRM);
	TPRM = (char **)malloc(sizeof(char *) * (j - i));
	if (ft_strcmp(PRM[0], "-i") == 0)
		return (env_i(cpe));
	else
		return (env_nopt(cpe));
}
