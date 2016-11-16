/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:52:50 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/15 23:17:24 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**ft_initenv(char **env, int init, t_cpe *cpe)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (shlvl_pres(env) + 1 + init));
	i = 0;
	while (env[i])
	{
		if (init == 1 || (ft_strncmp(env[i], "SHLVL=", 6) && init == 0))
			ret[i] = ft_strdup(env[i]);
		else if (val_lvl(env[i], /*creer fct pour verif si shlvl val valid*/) && init == 0)
			ret[i] = incr_sh(env, init, 5);
		i++;
	}
	if (init == 1)
	{
		ft_free_arr(env);
		ret[i] = ft_strjoin(PRM[0], "=");
		ret[++i] = 0;
	}
	else
		ret[i] = 0;
	return (ret);
}
