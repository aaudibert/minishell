/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/11 18:29:07 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		main(int ac, char **av, char **env)
{
	char *prompt;
	char *cmd;
	char **prm;

	//sous fonction prompt
	cmd = ft_strjoin("/bin/", ft_strdup(av[1]));
	prm = get_param(av);
	prompt = (char *)malloc(sizeof(char) * ft_strlen(get_name(env[16])));
	prompt = get_name(get_name(env[16]));
	(void)ac;
	ft_putendl(cmd);
	ft_putendl(prm[1]);
	while (42)
	{
		ft_putstr(BGREEN);
		ft_putstr("->  ");
		ft_putstr(BCYAN);
		ft_putstr(prompt);
		ft_putstr(RESET);
		ft_putchar(' ');
		get_next_line(0, av);
		execve(cmd, prm, NULL);
	}
	free(prompt);
	free(cmd);
	return (0);
}
