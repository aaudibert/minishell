/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:39:06 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/16 23:04:32 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_unsplit(char **s, char r)
{
	int		i;
	char	*ret;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp2 = ft_strdup("");
	while (s[i])
	{
		if (s[i + 1])
			tmp = ft_strjoin(s[i], &r);
		else
			tmp = ft_strdup(s[i]);
		ret = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		tmp2 = ft_strdup(ret);
		free(ret);
		i++;
	}
	return (ft_strdup(tmp2));
}
