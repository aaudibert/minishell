/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/11 20:39:02 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		main(int ac, char **av, char **env)
{
	char 	*prompt;
	char 	*cmd;
	char 	**prm;
	int		ex;

	ex = 1
	cmd = NULL;
	prm = NULL;
	if (ac > 1)
		cmd = ft_strdup(av[1]);
	if (ac > 2)
		prm = get_param(av);
	prompt = (char *)malloc(sizeof(char) * ft_strlen(get_name(env[6])));
	prompt = get_name(get_name(env[6]));
	while (42)
	{
		print_prompt(prompt, ex);
		get_next_line(0, av);
	}
	free(prompt);
	free(cmd);
	return (0);
}
