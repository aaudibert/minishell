/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 20:04:00 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/18 22:42:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			val_env(t_cpe *cpe, int v)
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
		free(PRM[v]);
		if (ft_strcmp(PRM[v], "$_"))
			PRM[v] = ft_strdup(tmp2);
		else
			PRM[v] = ft_strdup(OCMD);
		free(tmp2);
	}
	return (0);
}

void		handle_quote(t_cpe *cpe, int i)
{
	char *tmp;

	if (PRM[i][0] != '"')
		return ;
	if (ft_strcmp(PRM[i], "\"\""))
	{
		tmp = ft_strsub(PRM[i], 1, (ft_strlen(PRM[i]) - 2));
		free(PRM[i]);
		PRM[i] = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		free(PRM[i]);
		PRM[i] = ft_strdup("\n");
	}
}

int			quote_nb(t_cpe *cpe, int v)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (PRM[v][i])
	{
		if (PRM[v][i] == '"')
			nb++;
		i++;
	}
	return (nb % 2);
}

int			err_handle(t_cpe *cpe)
{
	int		i;

	i = 0;
	if (!PRM)
		return (0);
	while (PRM[i])
	{
		if (quote_nb(cpe, i) || !ft_strcmp(PRM[i], "\"$_\""))
		{
			ft_putendl("Unmatched \".");
			return (1);
		}
		handle_quote(cpe, i);
		if (ft_strcmp(PRM[i], "$") && val_env(cpe, i))
		{
			ft_putstr(PRM[i]);
			ft_putendl(": Undefined variable.");
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_echo(t_cpe *cpe)
{
	int i;

	i = 0;
	if (err_handle(cpe))
		return (1);
	if (PRM)
	{
		while (PRM[i])
		{
			ft_putstr_skip(PRM[i], '"');
			if (PRM[i + 1])
				ft_putchar(' ');
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
