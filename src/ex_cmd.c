/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:22:56 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/20 20:49:25 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_builtins(t_cpe *cpe)
{
	if (ft_strcmp(CMD, "exit") == 0)
		exit(0);
	if (ft_strcmp(CMD, "cd") == 0)
		return (/*ft_cd(cpe)*/0);
	else if (ft_strcmp(CMD, "env") == 0)
		return (print_arr(ENV) + 10);
	else if (ft_strcmp(CMD, "setenv") == 0)
	{
		if (!PRM)
			return (print_arr(ENV) + 10);
		if (arr_size(PRM) > 2)
		{
			ft_putendl("setenv: too many arguments");
			ft_putendl("usage: setenv [name[value]]");
			return (11);
		}
		return (ft_setenv(cpe) + 10);
	}
	else if (ft_strcmp(CMD, "unsetenv") == 0)
		return (ft_unsetenv(cpe) + 10);
	else
		return (-1);
}

int		ex_cmd(t_cpe *cpe)
{
	pid_t	father;
	int		w;

	father = fork();
	if (father > 0)
		wait(&w);
	if (father == 0)
	{
		RET = execve(TCMD, TPRM, ENV);
		exit(0);
	}
	return (RET);
}
