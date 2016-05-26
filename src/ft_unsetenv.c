/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 21:56:23 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/26 22:35:09 by aaudiber         ###   ########.fr       */
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
					ENV[j][ft_strlen(PRM[i])] == '=')
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
	if (!ENV[i])
		return (0);
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
	rt = (char **)malloc(sizeof(char *) * (arr_size(ENV) - check_var(cpe)));
	ft_putnbr(arr_size(ENV) - check_var(cpe));
	ft_putchar('\n');
	while (ENV[i])
	{
		ft_putstr("pre skip ");
		ft_putstr("i == ");
		ft_putnbr(i);
		ft_putchar('\n');
		while (skip_var(cpe, i))
			i++;
		ft_putstr("post skip ");
		ft_putstr("i == ");
		ft_putnbr(i);
		ft_putchar('\n');
		if (ENV[i])
		{
			ft_putendl(ENV[i]);
			ft_putstr("dup ");
			ft_putstr("i == ");
			ft_putnbr(i);
			ft_putchar('\n');
			rt[++j] = ft_strdup(ENV[i]);
			ft_putendl(rt[j]);
			ft_putnbr(j);
			ft_putchar('\n');
		}
		else
			break ;
		i++;
	ft_putendl("----------------------");
	}
	++j;
	rt[j] = 0;
	ft_putnbr(j);
	ft_putchar('\n');
	print_arr(rt);
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
		ft_putendl("--PRINT ENV--");
		print_arr(rt);
		ft_putendl("-------------");
		ft_free_arr(ENV);
		ENV = rt;
	}
	else
		ENV[0] = 0;
	return (0);
}
