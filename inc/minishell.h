/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:29:47 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/25 22:10:52 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <limits.h>
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
# define CMD			cpe->cmd
# define TCMD			cpe->tcmd
# define PATH			cpe->path
# define ENV			cpe->env
# define PRM			cpe->prm
# define TPRM			cpe->tprm
# define RET			cpe->ret

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct			s_cpe
{
	int					ret;
	char				*cmd;
	char				*tcmd;
	char				**path;
	char				**env;
	char				**prm;
	char				**tprm;
}						t_cpe;

char					*print_prompt(char *prompt, int ex);
int						get_next_line(int const fd, char **line);
char					*get_name(char **env, char *s, int len);
char					*get_cdn(char *s, int m);
char					**get_param(char **av);
char					**get_tparam(char **av);
int						valid_cmd(t_cpe *cpe);
int						check_builtins(t_cpe *cpe);
int						ex_cmd(t_cpe *cpe);
int						ft_setenv(t_cpe *cpe);
int						ft_unsetenv(t_cpe *cpe);
char					**ft_initenv(char **env, int init);
void					ft_print_env(char **env);
int						get_env(char **env, char *val);
int						ft_chdir(t_cpe *cpe);
void					free_cpe(t_cpe *cpe, int i);
#endif
