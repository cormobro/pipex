/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:20:15 by febonaer          #+#    #+#             */
/*   Updated: 2023/03/17 16:56:05 by febonaer         ###   ########.fr       */
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
		return (0);
	res = ft_split(path, ':');
	return (res);
}

static void	ft_init_list(t_pipex *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY, 0777);
	if (data->infile == -1)
		ft_printerror("Infile FD error");
	data->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (data->outfile == -1)
		ft_printerror("Outfile FD error");
}

static int	ft_close_fd(t_pipex *data)
{
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(data->infile);
	close(data->outfile);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc == 5)
	{
		if (pipe(data.pipe) == -1)
			ft_printerror("Pipe error");
		ft_init_list(&data, argv);
		data.child_pid = fork();
		if (data.child_pid < 0)
			ft_printerror("Fork error");
		ft_childprocess(&data, envp, argv);
		data.parent_pid = fork();
		if (data.parent_pid < 0)
			ft_printerror("Fork error");
		ft_parentprocess(&data, envp, argv);
		return (ft_close_fd(&data));
	}
	else
		ft_printerror("Arguments error");
	return (0);
}
