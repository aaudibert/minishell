/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/12 16:35:58 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cpe		*set_cpe(int ac, char **av, char **env)
{
	t_cpe *ret;

	ret = (t_cpe*)malloc(sizeof(t_cpe));
	if (ac > 1)
		ret->cmd = ft_strdup(av[1]);
	if (ac > 2)
		ret->prm = get_param(av);
	ret->env = ft_setenv(env, NULL, NULL, 0);
	return (ret);
}

int			main(int ac, char **av, char **env)
{
	char 	*prompt;
	t_cpe	*cpe;
	int		ex;

	ex = 0;

	cpe = set_cpe(ac, av, env);
	prompt = (char *)malloc(sizeof(char) * ft_strlen(get_name(env[6])));
	prompt = get_name(get_name(env[6]));
	while (42)
	{
		print_prompt(prompt, ex);
		get_next_line(0, av);
	}
	free(prompt);
	return (0);
}
