/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:44:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/14 19:40:50 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_cpe(t_cpe *cpe, int i)
{
	if (cpe->cmd)
		free(cpe->cmd);
	if (cpe->prm)
		ft_free_arr(cpe->prm);
	else
		free(cpe->prm);
	if (i == 0)
	{
		ft_free_arr(cpe->env);
		free(cpe);
	}
}
