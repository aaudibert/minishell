/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/20 19:41:21 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cpe		*ft_initcpe(char **env)
{
	t_cpe	*cpe;

	cpe = (t_cpe *)malloc(sizeof(t_cpe));
	ft_bzero(cpe, sizeof(t_cpe));
	ENV = ft_initenv(env, 0);
	return (cpe);
}

void		set_cpe(t_cpe *cpe, char *cp)
{
	char	**av;

	av = ft_strsplit(cp, ' ');
	if (av[0])
	{
		CMD = ft_strdup(av[0]);
		TPRM = get_tparam(av);
		PRM = NULL;
		if (av[1])
			PRM = get_param(av);
	}
}

int			main(int ac, char **av, char **env)
{
	char	*prompt;
	t_cpe	*cpe;
	char	*line;

	ac = 0;
	(void)av;
	cpe = ft_initcpe(env);
	prompt = get_cdn(get_name(cpe->env, "PWD", 3));
	while (42)
	{
		print_prompt(prompt, ac);
		get_next_line(0, &line);
		set_cpe(cpe, line);
		ac = valid_cmd(cpe, ft_strsplit(get_name(ENV, "PATH=", 5), ':'));
		if (ac == 0)
			ac = ex_cmd(cpe);
		else if (ac == 10 || ac == 11)
			ac -= 10;
		free_cpe(cpe, 1);
	}
	free(line);
	free(prompt);
	free_cpe(cpe, 0);
	return (0);
}
