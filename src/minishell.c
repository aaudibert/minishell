/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/06/19 18:35:20 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		g_ex;

char		**noenv(void)
{
	char	**ret;
	char	*pwd;

	ret = (char **)malloc(sizeof(char *) * 3);
	pwd = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	ret[0] = ft_strdup("PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin");
	ret[1] = ft_strjoin("PWD=", getcwd(pwd, PATH_MAX));
	ret[2] = 0;
	return (ret);
}

t_cpe		*ft_initcpe(char **env)
{
	t_cpe	*cpe;
	char	*tmp;

	tmp = get_name(env, "PATH=", 5);
	cpe = (t_cpe *)malloc(sizeof(t_cpe));
	ft_bzero(cpe, sizeof(t_cpe));
	NENV = 0;
	OCMD = ft_strdup("");
	if (*env == NULL || !tmp)
	{
		ENV = noenv();
		HOME = "$home";
		OLDPWD = NULL;
	}
	else
	{
		ENV = ft_initenv(env, 0, cpe);
		HOME = get_name(env, "HOME=", 5);
		OLDPWD = get_name(env, "OLDPWD=", 7);
	}
	PATH = ft_strsplit(tmp, ':');
	free(tmp);
	return (cpe);
}

void		env_ch(t_cpe *cpe, int i, int j)
{
	int o;

	o = 0;
	while (ENV[o])
	{
		if (ft_strncmp(ENV[o], "OLDPWD=", 7) == 0)
		{
			if (OLDPWD)
				free(OLDPWD);
			OLDPWD = get_name(ENV, "OLDPWD=", 7);
		}
		o++;
	}
	if (ENV[i])
	{
		free(PATH);
		PATH = ft_strsplit(get_name(ENV, "PATH=", 5), ':');
	}
	if (ENV[j])
	{
		free(HOME);
		HOME = get_name(ENV, "HOME=", 5);
	}
}

int			set_cpe(t_cpe *cpe, char *cp, int ac)
{
	char	**av;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ENV[i] && ft_strncmp(ENV[i], "PATH=", 5))
		i++;
	while (ENV[j] && ft_strncmp(ENV[j], "HOME=", 5))
		j++;
	av = param_quote(cp);
	if (av[0])
	{
		CMD = ft_strdup(av[0]);
		TPRM = get_tparam(av, HOME);
		PRM = NULL;
		env_ch(cpe, i, j);
		if (av[1])
			PRM = get_param(av, HOME);
	}
	return (valid_cmd(cpe, ac));
}

int			main(int ac, char **av, char **env)
{
	t_cpe	*cpe;
	char	*line;
	char	*prompt;

	ac = 0;
	(void)av;
	prompt = (char *)malloc(sizeof(char));
	cpe = ft_initcpe(env);
	check_sign();
	while (42)
	{
		prompt = print_prompt(prompt, ac, HOME);
		if (get_next_line(0, &line) == 0)
			exit(0);
		ac = set_cpe(cpe, line, ac);
		g_ex = 0;
		if (ac == 0)
			ac = ex_cmd(cpe);
		free_cpe(cpe, 1);
	}
	free(line);
	free(prompt);
	free_cpe(cpe, 0);
	return (0);
}
