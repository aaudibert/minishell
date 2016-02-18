/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/18 21:01:56 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cpe		*set_cpe(t_cpe *cpe, char *cp)
{
	char	**av;

	av = ft_strsplit(cp, ' ');
	if (av[0])
	{
		CMD = ft_strdup(av[0]);
		TPRM = get_tparam(av);
	}
	else
	{
		CMD = 0;
		TPRM = 0;
		return (cpe);
	}
	if (av[1])
		PRM = get_param(av);
	else
		PRM = 0;
	return (cpe);
}

void		sh_inst(t_cpe *cpe, int ex, char *prompt, char *line)
{
	print_prompt(prompt, ex);
	get_next_line(0, &line);
	cpe = set_cpe(cpe, line);
	ex = valid_cmd(cpe, ft_strsplit(get_name(ENV, "PATH=", 5), ':'));
	if (ex == 0)
		ex = ex_cmd(cpe);
	else if (ex == 10 || ex == 11)
		ex -= 10;
	free_cpe(cpe, 1);
}

int			main(int ac, char **av, char **env)
{
	char	*prompt;
	t_cpe	*cpe;
	int		ex;
	char	*line;

	ex = 0;
	line = NULL;
	(void)ac;
	(void)av;
	cpe = (t_cpe*)malloc(sizeof(t_cpe));
	cpe->env = ft_initenv(env, 0);
	prompt = get_cdn(get_name(cpe->env, "PWD", 3));
	while (42)
		sh_inst(cpe, ex, prompt, line);
	free(line);
	free(prompt);
	free_cpe(cpe, 0);
	return (0);
}
