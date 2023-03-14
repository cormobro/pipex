/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:20:15 by febonaer          #+#    #+#             */
/*   Updated: 2023/03/02 15:57:32 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Includes/pipex.h"

char	**get_path(char **envp)
{
	char	*path;
	char	**res;

	while (*envp)
	{
		if (ft_strstr(*envp, "PATH") != 0)
			break ;
		envp++;
	}
	if (!envp)
		return (0);
	path = ft_substr(*envp, 5, ft_strlen(*envp));
	if (!path)
		return(0);
	res = ft_split(path, ':');

	return (res);
}

void	ft_init_list(t_pipex *list, int fd1, int fd2, char **envp)
{
	list->infile = fd1;
	list->outfile = fd2;
	list->path = get_path(envp);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	t_pipex	list;

	(void)argv;
	ft_init_list(&list, fd1, fd2, envp);
}
int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data.path = get_path(envp);
	if (argc == 5)
	{
		if (pipe(data.pipe) == -1)
			ft_printerror("Pipe error");
		data.parent_pid = fork();
		if (data.parent_pid < 0)
			ft_printerror("Fork error");
		if (data.parent_pid == 0)
			ft_childprocess(&data, envp, argv);
		waitpid(data.parent_pid, NULL, 0);
		ft_parentprocess(&data, envp, argv);
	}
	else
		ft_printerror("Arguments error");
	return (0);
}
