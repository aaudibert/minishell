/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/11/20 14:35:11 by aaudiber         ###   ########.fr       */
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
	cpe->ppt = (char *)malloc(sizeof(char));
	OCMD = ft_strdup("");
	if (*env == NULL)
	{
		ENV = noenv();
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

void		env_ch(t_cpe *cpe, int i, int j, int o)
{
	char	*tmp;

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
		ft_free_arr(PATH);
		tmp = get_name(ENV, "PATH=", 5);
		PATH = ft_strsplit(tmp, ':');
		free(tmp);
	}
	if (ENV[j])
	{
		free(HOME);
		HOME = get_name(ENV, "HOME=", 5);
	}
}

int			set_cpe(t_cpe *cpe, int ac)
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
	av = param_quote(cpe);
	free(cpe->line);
	if (av[0])
	{
		CMD = ft_strdup(av[0]);
		TPRM = get_tparam(av, HOME);
		PRM = NULL;
		env_ch(cpe, i, j, 0);
		if (av[1])
			PRM = get_param(av, HOME);
	}
	ft_free_arr(av);
	return (valid_cmd(cpe, ac));
}

int			main(int ac, char **av, char **env)
{
	t_cpe	*cpe;

	ac = 0;
	(void)av;
	cpe = ft_initcpe(env);
	check_sign();
	ac = 0;
	while (42)
	{
		cpe->line = (char *)malloc(sizeof(char) * ARG_MAX + 1);
		ft_bzero(cpe->line, sizeof(cpe->line));
		cpe->ppt = print_prompt(cpe->ppt, ac, HOME);
		if (get_cmdl(cpe->line) == 0)
			exit_msg(-1, "exit", cpe);
		ac = set_cpe(cpe, ac);
		g_ex = 0;
		if (ac == 0)
			ac = ex_cmd(cpe);
		free_cpe(cpe, 1);
	}
	free(cpe->ppt);
	free_cpe(cpe, 0);
	return (0);
}
