/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:44:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/19 20:25:52 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_cpe(t_cpe *cpe, int i)
{
	ft_putendl("------------");
	free(CMD);
	ft_putendl("------------");
	if (PRM)
		ft_free_arr(PRM);
	ft_putendl("-----------");
	if (TCMD)
		free(TCMD);
	ft_putendl("-----------");
	if (TPRM)
		ft_free_arr(TPRM);
	if (i == 0)
	ft_putendl("-----------");
	{
		ft_free_arr(ENV);
		free(cpe);
	}
	ft_putendl("-----------");
}
