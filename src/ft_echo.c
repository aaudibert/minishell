/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 20:04:00 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/16 23:05:37 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		val_env(t_cpe *cpe, int v)
{
	char	*tmp;
	char	*tmp2;

	if (PRM[v][0] == '$')
	{
		tmp2 = ft_strsub(PRM[v], 1, ft_strlen(PRM[v]));
		tmp = ft_strjoin(tmp2, "=");
		free(tmp2);
		if ((tmp2 = get_name(ENV, tmp, ft_strlen(tmp))) == NULL)
		{
			free(tmp);
			free(tmp2);
			return (1);
		}
		free(tmp);
		if (ft_strcmp(PRM[v], "_="))
		{
			free(PRM[v]);
			PRM[v] = ft_strdup(tmp2);
		}
		free(tmp2);
	}
	return (0);
}

int		err_handle(t_cpe *cpe)
{
	int		i;

	i = 0;
	while (PRM[i])
	{
		if ((PRM[i][0] == '"' && PRM[i][ft_strlen(PRM[i])] != '"') ||
				(PRM[i][0] != '"' && PRM[i][ft_strlen(PRM[i])] == '"'))
		{
			ft_putendl("Unmatched \".");
			return (1);
		}
		else if (val_env(cpe, i))
		{
			ft_putstr(PRM[i]);
			ft_putendl(": Undefined variable.");
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_echo(t_cpe *cpe)
{
	int i;

	i = 0;
	if (err_handle(cpe))
		return (1);
	while (PRM[i])
	{
		//finish him
		i++;
	}
	return (0);
}
