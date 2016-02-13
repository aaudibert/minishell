/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/13 21:17:08 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cpe		*set_cpe(t_cpe *ret, char *cp)
{
	char	**av;

	av = ft_strsplit(cp, ' ');
	if (av[0])
		ret->cmd = ft_strdup(av[0]);
	else
		ret->cmd = 0;
	if (av[1])
		ret->prm = get_param(av);
	else
		ret->prm = NULL;
	return (ret);
}

int			main(int ac, char **av, char **env)
{
	char	*prompt;
	t_cpe	*cpe;
	int		ex;
	char	*line;

	ex = 0;
	prompt = (char *)malloc(sizeof(char) * ft_strlen(get_name(env[6])));
	prompt = get_name(get_name(env[6]));
	(void)ac;
	(void)av;
	cpe = (t_cpe*)malloc(sizeof(t_cpe));
	cpe->env = ft_initenv(env, 0);
	while (42)
	{
		print_prompt(prompt, ex);
		get_next_line(0, &line);
		cpe = set_cpe(cpe, line);
		ex = valid_cmd(cpe);
		free_cpe(cpe);
	}
	free(prompt);
	free(cpe);
	return (0);
}
