/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:56:09 by aaudiber          #+#    #+#             */
/*   Updated: 2016/03/08 20:42:22 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signhandler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		if (g_ex == 0)
			print_prompt(NULL, 1, NULL);
		g_ex = 0;
	}
}

void	check_sign(void)
{
	signal(SIGINT, signhandler);
}
