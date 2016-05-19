/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/19 19:25:23 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		g_ex;

char		**noenv(t_cpe *cpe)
{
/*	char	*line;
	char	*prompt;

	prompt = (char *)malloc(sizeof(char));
	check_sign();
	while (42)
	{
		prompt = print_prompt(prompt, 1, NULL);
		get_next_line(0, &line);
		if (ft_strncmp(line, "exit", 4) == 0)
			exit(0);
	}*/
	char	**ret;
	int		i;

}

t_cpe		*ft_initcpe(char **env)
{
	t_cpe	*cpe;
	char	*tmp;

	tmp = get_name(env, "PATH=", 5);
	cpe = (t_cpe *)malloc(sizeof(t_cpe));
	ft_bzero(cpe, sizeof(t_cpe));
	if (*env == NULL || !tmp)
	{
		ENV = noenv(cpe);
		PATH = ft_strsplit("/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin", ':');
	}
	else
	{
		ENV = ft_initenv(env, 0);
		PATH = ft_strsplit(get_name(env, "PATH=", 5), ':');
		HOME = get_home(PATH[0]);
	}
	free(tmp);
	return (cpe);
}

int			set_cpe(t_cpe *cpe, char *cp, int ac)
{
	char	**av;

	cp = replace_char(cp, '\t', ' ');
	av = ft_strsplit(cp, ' ');
	if (av[0])
	{
		CMD = ft_strdup(av[0]);
		TPRM = get_tparam(av, HOME);
		PRM = NULL;
		if (av[1])
			PRM = get_param(av, HOME);
	}
	return (valid_cmd(cpe, ac));
}

int			main(int ac, char **av, char **env)
{
	t_cpe	*cpe;
	char	*line;
	char	*prompt;

	ac = 0;
	(void)av;
	prompt = (char *)malloc(sizeof(char));
	cpe = ft_initcpe(env);
	check_sign();
	while (42)
	{
		prompt = print_prompt(prompt, ac, HOME);
		get_next_line(0, &line);
		ac = set_cpe(cpe, line, ac);
		g_ex = 0;
		if (ac == 0)
			ac = ex_cmd(cpe);
		free_cpe(cpe, 1);
	}
	free(line);
	free(prompt);
	free_cpe(cpe, 0);
	return (0);
}
