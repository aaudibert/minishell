/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:22:56 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/31 22:07:38 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		check_cmd_path(t_cpe *cpe)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	while (PATH[i])
	{
		len = ft_strlen(PATH[i]) - 1;
		if (!ft_strncmp(CMD, PATH[i], len))
		{
			tmp = ft_strsub(CMD, len + 2, (ft_strlen(CMD) - len));
			TCMD = ft_strdup(CMD);
			free(CMD);
			CMD = tmp;
			return ;
		}
		i++;
	}
}

int			exec_exit(t_cpe *cpe)
{
	if (ft_strcmp(CMD, "exit") == 0 && PRM)
	{
		ft_putendl("exit: Expression Syntax.");
		return (11);
	}
	else
		exit(0);
}

int			check_envi(t_cpe *cpe)
{
	int i;

	i = 0;
	if (NENV && ft_strcmp(PRM[0], "env") && ft_strcmp(PRM[0], "unsetenv") &&
			ft_strcmp(PRM[0], "setenv"))
		return (10);
	if (!PRM)
		return (print_arr(ENV) + 10);
	else if (!ft_strcmp(PRM[0], "-i"))
	{
		while (PRM[i + 1])
		{
			free(PRM[i]);
			PRM[i] = ft_strdup(PRM[i + 1]);
			i++;
		}
		free(PRM[i]);
		PRM[i] = 0;
		NENV = 1;
	}
	if (!NENV)
		check_builtins(cpe);
	return (-1);
}

int			check_builtins(t_cpe *cpe)
{
	check_cmd_path(cpe);
	if (ft_strcmp(CMD, "exit") == 0)
		return (exec_exit(cpe));
	else if (ft_strcmp(CMD, "cd") == 0)
		return (ft_chdir(cpe));
	else if (ft_strcmp(CMD, "env") == 0)
		return (check_envi(cpe));
	else if (ft_strcmp(CMD, "setenv") == 0)
	{
		if (!PRM)
			return (print_arr(ENV) + 10);
		if (arr_size(PRM) > 2)
		{
			ft_putendl("setenv: Too many arguments");
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

int			ex_cmd(t_cpe *cpe)
{
	pid_t	father;
	int		w;

	g_ex = 1;
	father = fork();
	if (father > 0)
		wait(&w);
	if (father == 0)
	{
		execve(TCMD, TPRM, ENV);
		exit(0);
	}
	g_ex = 0;
	return (0);
}
