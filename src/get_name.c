/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:46:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/23 23:02:48 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*ch_home(char *av, char *home)
{
	int		i;
	char	*ret;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (av[i])
	{
		if (av[i] == '~')
			break;
		i++;
	}
	if (av[i])
	{
		//Final fix ?
		tmp = ft_strsub(av, 0, i - 1);
		tmp2 = ft_strjoin(tmp, home);
		free(tmp);
		tmp = ft_strsub(av, i + 1, (ft_strlen(av) - i));
		ret = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		ret = ft_strdup(av);
	ft_putendl(ret);
	return (ret);
}

char		**get_param(char **av, char *home)
{
	char	**ret;
	int		i;
	int		j;

	ret = (char**)malloc(sizeof(char *) * arr_size(av));
	i = 0;
	j = 1;
	while (av[j])
	{
		if (ft_strcmp(av[j], "~") != 0 || (!home && !ft_strcmp(av[j], "~")))
			ret[i] = ch_home(av[j], home);
			//ret[i] = ft_strdup(av[j]);
		else
			ret[i] = ft_strdup(home);
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}

char		**get_tparam(char **av, char *home)
{
	char	**ret;
	int		i;

	ret = (char**)malloc(sizeof(char *) * arr_size(av) + 1);
	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "~") != 0 || (!home && !ft_strcmp(av[i], "~")))
			ret[i] = ch_home(av[i], home);
		else
			ret[i] = ft_strdup(home);
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
