/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/25 22:11:47 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		noenv(void)
{
	char	*line;
	char	*prompt;

	prompt = (char *)malloc(sizeof(char));
	while (42)
	{
		prompt = print_prompt(prompt, 1);
		get_next_line(0, &line);
	}
}

t_cpe		*ft_initcpe(char **env)
{
	t_cpe	*cpe;

	cpe = (t_cpe *)malloc(sizeof(t_cpe));
	if (*env == NULL)
		noenv();
	ft_bzero(cpe, sizeof(t_cpe));
	ENV = ft_initenv(env, 0);
	PATH = ft_strsplit(get_name(ENV, "PATH=", 5), ':');
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
	prompt = (char *)malloc(sizeof(char));
	cpe = ft_initcpe(env);
	while (42)
	{
		prompt = print_prompt(prompt, ac);
		get_next_line(0, &line);
		set_cpe(cpe, line);
		ac = valid_cmd(cpe);
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
