/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 15:05:40 by ysoto             #+#    #+#             */
/*   Updated: 2014/03/27 09:55:32 by fperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "../libft/libft.h"
# include "ft_struct.h"
# define FAIL 256

/*
** file tools.c
*/

int		search_num_line(char ***env, char *sch);
char	*search_line(char ***env, char *sch);
int		count_char_double(char *string, char c);
int		ft_check_redi(char *str);

/*
** file ft_exec.c
*/

char	**ft_path(char ***env, char *cmd);
void	ft_execute_cmd(char **path, char **cmd, char **env, int *flagados);
void	ft_launch_exec(char *command, char ***env, int *execve_flag);
char	*get_path_cmd(char **env, char *cmd);

/*
** file ft_operator.c
*/

void	split_exec_ampersand(char ***env, char *command, int *execve_flag);
int		ampersand_and_or(char ***env, char *command, int *execve_flag);
void	no_ampersand_and_or(char ***env, char *command, int *execve_flag);
char	*check_ampersand(char *string, int *flag);
int		check_or(char *string, int flag);
void	ft_exec_cmd(char *path, char **cmd_arg, char **env, int *execve_flag);

/*
** file ft_clean.c
*/

char	*ft_del_tab(char *line);
char	*ft_del_tilde(char *cmd, char ***env);
char	**get_clean_arg(char *cmd, char **env);

/*
** file builtin.c
*/

int		builtin(char ***env, char **cmd);

/*
** file builtin_cd.c
*/

void	builtin_cd(char ***env, char **cmd);

/*
** file builtin_setenv.c
*/

void	builtin_setenv(char ***env, char **cmd);

/*
** file builtin_unsetenv.c
*/

void	builtin_unsetenv(char ***env, char **cmd);

/*
** file ft_strsplit_index.c
*/

char	**ft_strsplit_index(char *s, char c);

/*
** file pipe_fork.c
*/

int		exec_child(char ***env, char *cmd, int *pi, int *execvfe_f);
int		exec_father(char ***env, char *cmd, int *pi, int *execve_f);

/*
** file ft_pipe.c
*/

void	exec_pipe(char ***env, char *command, int *execve_flag);

/*
** file ft_redi_left.c
*/

int		exec_redi_left(char *cmd, char ***env, int *execve_f);

/*
** file ft_redi_right.c
*/

int		exec_redi_right(char *cmd, char ***env, int *execvef_flag);

/*
** file ft_doublerd.c
*/

int		exec_doublerd(char *cmd, char ***env, int *execve_flag);

/*
** file ft_rd_all.c
*/

int		ft_rd(char *command, char ***env, int *execve_flag);

/*
** file ft_error.c
*/

void	ft_error(char *cmd);
int		error_setenv(char **cmd);
int		error_unsetenv(char **cmd);
int		ft_error2(char *cmd);
int		ft_error_null_command(char *command);

/*
** file error2.c
*/

int		*call_pipe(int *pi);
void	ft_fork_error(int *pi);
void	ft_error_redi(char *str);

#endif
