/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:34:08 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/22 18:38:50 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


void		print_prompt(t_cpe *cpe, char *prompt, int ex)
{	if (ex == -1)
	{
		ft_putstr(BRED);
		ft_putstr("->  ");
		ft_putstr(BCYAN);
		ft_putstr(prompt);
		ft_putstr(RESET);
		ft_putchar(' ');
		return ;
	}
	free(prompt);
	prompt = get_cdn(get_name(ENV, "PWD", 3));
	if (ex == 0)
		ft_putstr(BGREEN);
	else
		ft_putstr(BRED);
	ft_putstr("->  ");
	ft_putstr(BCYAN);
	ft_putstr(prompt);
	ft_putstr(RESET);
	ft_putchar(' ');
}
