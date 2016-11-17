/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:22:56 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/17 20:46:18 by aaudiber         ###   ########.fr       */
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
			free(TCMD);
			TCMD = ft_strdup(CMD);
			free(CMD);
			CMD = tmp;
			return ;
		}
		i++;
	}
}

int			no_digit(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int			exec_err(t_cpe *cpe)
{
	int i;

	i = 0;
	if (!PRM)
		exit_msg(0, "", cpe);
	if (PRM[0] && (PRM[1] || no_digit(PRM[0])))
	{
		ft_putendl("exit: Expression Syntax.");
		return (11);
	}
	else
	{
		while (PRM[0][i])
		{
			if (!ft_isdigit(PRM[0][i]))
			{
				ft_putendl("exit: Badly formed number.");
				return (11);
			}
			i++;
		}
		exit_msg(ft_atoi(PRM[0]), "", cpe);
	}
	return (10);
}

int			check_builtins(t_cpe *cpe)
{
	check_cmd_path(cpe);
	if (ft_strcmp(CMD, "exit") == 0)
		return (exec_err(cpe));
	if (ft_strcmp(CMD, "echo") == 0)
		return (ft_echo(cpe) + 10);
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
		if (!NENV)
			execve(TCMD, TPRM, ENV);
		else
			execve(TCMD, TPRM, NULL);
		exit(0);
	}
	g_ex = 0;
	return (0);
}
