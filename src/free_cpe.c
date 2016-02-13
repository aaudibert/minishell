/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cpe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:20:06 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/13 14:50:29 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		free_cpe(t_cpe *cpe)
{
	free(cpe->cmd);
	ft_free_arr(cpe->prm);
	ft_free_arr(cpe->env);
	free(cpe);
}
