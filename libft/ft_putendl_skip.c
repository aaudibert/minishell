/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_skip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 22:32:07 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/18 22:34:03 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_skip(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}
