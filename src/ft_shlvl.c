/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:24:57 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/16 14:53:38 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			shlvl_pres(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if ()
			return (arr_size(env));
		else if ()
			return (arr_size(env) - 1);
		i++;
	}
	return (arr_size(env) + 1);
}

int			val_lvl(char *env)
{
	if (ft_strncmp(env, "SHLVL=", 6) && )
}

char		*incr_sh(char **env, int init, int lvl)
{
	char	*ret;
	char	*tmp;

	tmp = get_name(env, "SHLVL=", 6);
	while (tmp[++lvl])
	{
		if (!ft_isdigit(tmp[lvl]))
		{
			if (init == 0)
			{
				free(tmp);
				return (ft_strdup("SHLVL=1"));
			}
			ret = ft_strjoin("SHLVL=", tmp);
			free(tmp);
			return (ret);
		}
	}
	lvl = ft_atoi(tmp) + 1;
	free(tmp);
	tmp = ft_itoa(lvl);
	ret = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	return (ret);
}

int			valid_env(char *val)
{
	int i;

	i = 1;
	if (!ft_isalpha(val[0]) && val[0] != '_')
	{
		ft_putendl("setenv: Variable name must begin with a letter.");
		return (1);
	}
	while (val[i])
	{
		if (!ft_isalnum(val[i]) && val[i] != '_')
		{
			ft_putstr("setenv: Variable must contain alphanumeric");
			ft_putendl(" characters.");
			return (1);
		}
		i++;
	}
	return (0);
}
