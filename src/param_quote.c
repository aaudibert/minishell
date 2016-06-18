/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 16:03:39 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/18 22:19:28 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			get_size(char *s)
{
	int i;
	int j;
	int ret;

	i = 0;
	ret = 1;
	while (s[i++])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			while ((s[i] == ' ' || s[i] == '\t') && s[i])
				i++;
			if (s[i])
				ret++;
		}
		if (s[i] == '"')
		{
			j = i + 1;
			while (s[j] != '"' && s[j])
				j++;
			if (s[j])
				i = j;
		}
	}
	return (ret);
}

char		*get_dup(char *s, int st)
{
	int i;
	int j;

	i = st;
	while (s[i] && s[i] != ' ' &&  s[i] != '\t')
	{
		if (s[i] == '"')
		{
			j = i + 1;
			while (s[j] != '"' && s[j])
				j++;
			if (s[j])
				i = j;
		}
		i++;
	}
	return (ft_strsub(s, st, (i - st)));
}

int			skip_sp(char *s, int i)
{
	int j;

	while (s[i] && s[i] != ' ' &&  s[i] != '\t')
	{
		if (s[i] == '"')
		{
			j = i + 1;
			while (s[j] != '"' && s[j])
				j++;
			if (s[j])
				i = j;
		}
		i++;
	}
	return (i);
}

char		**dup_prm(char *s)
{
	char	**ret;
	int		i;
	int		j;

	ret = (char **)malloc(sizeof(char *) * (get_size(s) + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
		if (!s[i])
			break;
		ret[j] = get_dup(s, i);
		i = skip_sp(s, i);
		j++;
	}
	ret[j] = 0;
	return (ret);
}

char		**param_quote(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && (s[i] != ' ' || s[i] != '\t'))
	{
		if (s[i] == '"')
			j++;
		i++;
	}
	if (j <= 1)
	{
		s = replace_char(s, '\t', ' ');
		return (ft_strsplit(s, ' '));
	}
	return (dup_prm(s));
}
