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

/*static void	ft_wait(t_pipex *data)
{
	int	status;
	int	exit_status;

	waitpid(data->child_pid, &status, 0);
	if ( WIFEXITED(status) )
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status == 1)
			exit(EXIT_FAILURE);
	}
}*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data.path = get_path(envp);
	if (argc == 5)
	{
		if (pipe(data.pipe) == -1)
			ft_printerror("Pipe error");
		data.child_pid = fork();
		if (data.child_pid < 0)
			ft_printerror("Fork error");
		ft_childprocess(&data, envp, argv);
		//ft_wait(&data);
		waitpid(data.child_pid, NULL, 0);
		data.parent_pid = fork();
		if (data.parent_pid < 0)
			ft_printerror("Fork error");
		ft_parentprocess(&data, envp, argv);
		close(data.pipe[0]);
		close(data.pipe[1]);
		close(data.infile);
		close(data.outfile);
		waitpid(data.child_pid, NULL, 0);
	}
	else
		ft_printerror("Arguments error");
	return (0);
}
