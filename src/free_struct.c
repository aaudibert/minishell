/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:44:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/22 18:26:36 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		del_cpe(t_cpe *cpe)
{
	if (PATH)
		free(PATH);
	if (ENV)
		ft_free_arr(ENV);
	free(cpe);
}

void		free_cpe(t_cpe *cpe, int i)
{
	if (CMD)
	{
		free(CMD);
		CMD = NULL;
	}
	if (PRM)
	{
		ft_free_arr(PRM);
		PRM = NULL;
	}
	if (TCMD)
	{
		free(TCMD);
		TCMD = NULL;
	}
	if (TPRM)
	{
		ft_free_arr(TPRM);
		TPRM = NULL;
	}
	if (i == 0)
		del_cpe(cpe);
}
