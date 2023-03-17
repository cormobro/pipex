/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:40:27 by febonaer          #+#    #+#             */
/*   Updated: 2023/03/17 15:49:16 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_childprocess(t_pipex *data, char **envp, char **argv)
{
	if (data->child_pid == 0)
	{
		dup2(data->pipe[1], 1);
		dup2(data->infile, 0);
		close(data->pipe[0]);
		data->path = get_path(envp);
		ft_exec_cmd(data, argv[2], envp);
	}
}

void	ft_parentprocess(t_pipex *data, char **envp, char **argv)
{
	if (data->parent_pid == 0)
	{
		dup2(data->pipe[0], 0);
		dup2(data->outfile, 1);
		close(data->pipe[1]);
		data->path = get_path(envp);
		ft_exec_cmd(data, argv[3], envp);
	}
}
