/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:22:56 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/16 22:14:19 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_builtins(t_cpe *cpe)
{
	if (ft_strcmp(CMD, "cd") == 0)
		return (/*ft_cd(cpe)*/0);
	else if (ft_strcmp(CMD, "env") == 0)
	{
		print_arr(ENV);
		return (0);
	}
	else if (ft_strcmp(CMD, "setenv") == 0)
	{
		if (!PRM)
		{
			print_arr(ENV);
			return (0);
		}
		return (0);
	}
	else if (ft_strcmp(CMD, "unsetenv") == 0)
		return (ft_unsetenv(cpe));
	else
		return (-1);
}

int		ex_cmd(t_cpe *cpe)
{
	pid_t	father;
	int		w;

	if (ft_strcmp(CMD, "exit") == 0)
		exit(0);
	father = fork();
	if (check_builtins(cpe) >= 0)
		return (check_builtins(cpe));
	if (father > 0)
		wait(&w);
	if (father == 0)
	{
		if (execve(CMD, PRM++, ENV))
			return (0);
		else
			return (1);
		exit(0);
	}
	return (1);
}
