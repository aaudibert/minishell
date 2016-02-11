/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:46:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/11 18:10:28 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**get_param(char **av)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[i])
		i++;
	i = 2;
	ret = (char**)malloc(sizeof(char *) * i - 1);
	while (av[i])
	{
		ret[j] = av[i];
		i++;
		j++;
	}
	return (ret);
}

char		*get_name(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = ft_strlen(s) - 2;
	j = 0;
	while (s[i] != '/' && i >= 0)
		i--;
	i++;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	while (s[i] != '/' && s[i] != '\0')
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	return (ret);
}
