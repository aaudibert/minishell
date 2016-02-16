/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:22:56 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/16 17:12:06 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.c"

int		ex_cmd(t_cpe *cpe)
{
	pid_t father;

	father = fork();
	if (father > 0)
		wait(&father);
	if (father == 0)
	{
		if (execve(CMD, PRM, ENV))
			return (0);
		else
			return (1);
		exit(0);
	}
}
