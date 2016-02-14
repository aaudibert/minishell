/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:29:47 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/14 19:37:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define RESET			"\x1B[0m"
# define RED			"\x1B[31m"
# define BRED			"\x1B[1;31m"
# define GREEN			"\x1B[32m"
# define BGREEN			"\x1B[1;32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGENTA		"\x1B[35m"
# define CYAN			"\x1B[36m"
# define BCYAN			"\x1B[1;36m"

# define BUFF_SIZE		1

typedef struct dirent	t_dirent;

typedef struct			s_cpe
{
	char				*cmd;
	char				**env;
	char				**prm;
}						t_cpe;

void					print_prompt(char *prompt, int ex);
int						get_next_line(int const fd, char **line);
char					*get_name(char *s);
char					**get_param(char **av);
char					*get_path(char **env);
char					**ft_setenv(char **env, char *name, char *value, int init);
char					**ft_initenv(char **env, int init);
void					ft_print_env(char **env);
int						valid_cmd(t_cpe *cpe);
void					free_cpe(t_cpe *cpe, int i);
#endif
