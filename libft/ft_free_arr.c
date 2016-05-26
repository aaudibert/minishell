/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:14:55 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/26 15:38:56 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

void		ft_free_arr(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	ft_putendl("--FREE ARR--");
	while (arr[i])
	{
		ft_putendl(arr[i]);
		free(arr[i]);
		i++;
	}
	ft_putendl("-----------");
	free(arr);
}
