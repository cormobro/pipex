/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:04:08 by febonaer          #+#    #+#             */
/*   Updated: 2023/03/17 15:44:44 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		pipe[2];
	int		infile;
	int		outfile;
	pid_t	parent_pid;
	pid_t	child_pid;
	char	**path;
	char	**cmd;
}	t_pipex;

char	**get_path(char **envp);
char	*ft_strstr(const char *str, const char *substr);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	pipex(int fd1, int fd2, char **argv, char **envp);
void	ft_printerror(char *err);
void	ft_childprocess(t_pipex *data, char **envp, char **argv);
void	ft_parentprocess(t_pipex *data, char **envp, char **argv);
void	ft_exec_cmd(t_pipex *data, char *cmds, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
