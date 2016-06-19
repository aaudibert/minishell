/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:39:06 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/19 19:28:04 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_unsplit(char **s, char *r)
{
	int		i;
	char	*ret;
	char	*tmp;
	char	*tmp2;

	i = 1;
	if (s[1])
		tmp2 = ft_strjoin(s[0], r);
	else
		tmp2 = ft_strdup(s[0]);
	while (s[i])
	{
		if (s[i + 1])
			tmp = ft_strjoin(s[i], r);
		else
			tmp = ft_strdup(s[i]);
		ret = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		tmp2 = ft_strdup(ret);
		free(ret);
		i++;
	}
	return (tmp2);
}
