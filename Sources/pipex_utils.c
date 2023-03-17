/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:43:07 by febonaer          #+#    #+#             */
/*   Updated: 2023/03/17 15:49:04 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(substr) || !str)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (substr[j] && str[i + j] && substr[j] == str[i + j])
			j++;
		if (!substr[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*res;

	size = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len < size)
		size = len;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = (size_t)start;
	while (j < ft_strlen(s) && i < len)
	{
		res[i] = s[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_printerror(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	ft_exec_cmd(t_pipex *data, char *cmds, char **envp)
{
	int		i;
	char	*command;

	i = -1;
	data->cmd = ft_split(cmds, ' ');
	if (access(data->cmd[0], F_OK) == 0)
		execve(data->cmd[0], data->cmd, envp);
	while (data->path[++i])
	{
		command = ft_strjoin(data->path[i], "/");
		command = ft_strjoin(command, data->cmd[0]);
		if (access(command, F_OK) == 0)
			execve(command, data->cmd, envp);
		free(command);
	}
	i = -1;
	while (data->path[++i])
		free(data->path[i]);
	free(data->path);
	i = -1;
	while (data->cmd[++i])
		free(data->cmd[i]);
	free(data->cmd);
	ft_printerror("Error: command not found");
}
