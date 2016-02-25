/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:34:08 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/25 22:10:42 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


char		*print_prompt(char *prompt, int ex)
{
	char	tmp[PATH_MAX];
	char	*tmp2;

	getcwd(tmp, PATH_MAX);
	if (ft_strcmp(tmp, "/nfs/2014/a/aaudiber") == 0)
		tmp2 = ft_strdup("~");
	else
		tmp2 = get_cdn(tmp, 0);
	if (ft_strcmp(tmp, prompt) != 0)
	{
		free(prompt);
		prompt = ft_strdup(tmp2);
	}
	free(tmp2);
	if (ex == 0)
		ft_putstr_color("->  ", BGREEN);
	else
		ft_putstr_color("->  ", BRED);
	ft_putstr_color(prompt, BCYAN);
	ft_putchar(' ');
	return (prompt);
}
