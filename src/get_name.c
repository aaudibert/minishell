/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:46:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/03/06 18:24:27 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*get_home(char *path)
{
	size_t	i;

	i = 0;
	while (path[i] != '.')
		i++;
	return (ft_strsub(path, 0, i));
}

char		**get_param(char **av)
{
	char	**ret;
	int		i;
	int		j;

	ret = (char**)malloc(sizeof(char *) * arr_size(av));
	i = 0;
	j = 1;
	while (av[j])
	{
		ret[i] = ft_strdup(av[j]);
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}

char		**get_tparam(char **av)
{
	char	**ret;
	int		i;

	ret = (char**)malloc(sizeof(char *) * arr_size(av) + 1);
	i = 0;
	while (av[i])
	{
		ret[i] = ft_strdup(av[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		*get_cdn(char *s, int m)
{
	int		i;
	int		j;
	char	*ret;

	i = ft_strlen(s);
	j = 0;
	while (s[i] != '/')
		i--;
	i++;
	ret = (char *)malloc(sizeof(char) * ft_strlen(s - i));
	while (s[i] != '\0')
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j] = 0;
	if (m)
		free(s);
	return (ret);
}

char		*get_name(char **env, char *s, int len)
{
	int		p;
	int		i;
	char	*ret;

	p = 0;
	i = 0;
	while (env[p])
	{
		if (ft_strncmp(env[p], s, len) == 0)
			break ;
		p++;
	}
	if (!env[p])
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ft_strlen(env[p] + len) + 1);
	while (env[p][len] != '\0')
	{
		ret[i] = env[p][len];
		len++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
