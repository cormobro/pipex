/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:43:07 by febonaer          #+#    #+#             */
/*   Updated: 2022/11/03 15:03:40 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

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

