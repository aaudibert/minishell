/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:44:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/09/18 19:33:57 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		exit_msg(int i, char *s, t_cpe *cpe)
{
	free_cpe(cpe, 0);
	free(cpe->ppt);
	if (i == -1)
	{
		ft_putendl(s);
		exit(0);
	}
	else
		exit(i);
}

void		del_cpe(t_cpe *cpe)
{
	if (OCMD)
		free(OCMD);
	if (OLDPWD)
		free(OLDPWD);
	if (HOME)
		free(HOME);
	if (PATH)
		free(PATH);
	if (ENV)
		ft_free_arr(ENV);
	free(cpe);
}

void		get_ocmd(t_cpe *cpe)
{
	int		i;

	i = 0;
	if (OCMD)
	{
		free(OCMD);
		OCMD = NULL;
	}
	if (TPRM)
		OCMD = ft_unsplit(TPRM, " ");
	else
		OCMD = ft_strdup("");
}

void		free_cpe(t_cpe *cpe, int i)
{
	get_ocmd(cpe);
	if (CMD)
	{
		free(CMD);
		CMD = NULL;
	}
	if (PRM)
	{
		ft_free_arr(PRM);
		PRM = NULL;
	}
	if (TCMD)
	{
		free(TCMD);
		TCMD = NULL;
	}
	if (TPRM)
	{
		ft_free_arr(TPRM);
		TPRM = NULL;
	}
	if (i == 0)
		del_cpe(cpe);
}
