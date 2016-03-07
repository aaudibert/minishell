/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:56:09 by aaudiber          #+#    #+#             */
/*   Updated: 2016/03/07 20:17:03 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signhandler(int signum)
{
	(void)signum;
	ft_putchar('\n');
	print_prompt(NULL, 1, NULL);
}

void	check_sign(void)
{
	signal(SIGINT, signhandler);
}
