/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:04:08 by febonaer          #+#    #+#             */
/*   Updated: 2022/11/10 14:38:04 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
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
		pid_t	child_pid;
		pid_t	parent_pid;
		char	**path;
		char	**cmd;
}		t_pipex;

char	*ft_strstr(const char *str, const char *substr);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	ft_init_list(t_pipex *list, int fd1, int fd2, char **envp);
void	pipex(int fd1, int fd2, char **argv, char **envp);

#endif