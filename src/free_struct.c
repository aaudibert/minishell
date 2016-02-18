/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:44:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/18 21:06:59 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_cpe(t_cpe *cpe, int i)
{
	free(CMD);
	if (PRM)
		ft_free_arr(PRM);
	ft_putendl("----------------");
	free(TCMD);
	ft_putendl("----------------");
	if (TPRM)
		ft_free_arr(TPRM);
	else
		free(PRM);
	ft_putendl("----------------");
	if (i == 0)
	{
		ft_free_arr(cpe->env);
		free(cpe);
	}
	ft_putendl("----------------");
}
