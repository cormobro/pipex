/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:57:23 by febonaer          #+#    #+#             */
/*   Updated: 2022/11/10 11:57:56 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Includes/pipex.h"

static char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;

	if (!src)
		return (NULL);
	i = 0;
	copy = (char *)malloc((n + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	countwords(const char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	if (str[0] != c)
		words++;
	i = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static char	**split_free(char **tab, int l)
{
	while (l)
	{
		free(tab[l]);
		l--;
	}
	free(tab);
	return (0);
}

static char	**ft_split2(char const *s, char c, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
		{
			tab[k++] = ft_strndup((char *)&s[i], j);
			if (!tab[k - 1])
				return (split_free(tab, k - 2));
			i = i + j;
		}
		if (s[i])
			i++;
	}
	tab[k] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s || !ft_strlen(s))
	{
		tab = malloc((1) * sizeof(char *));
		if (!tab)
			return (0);
		tab[0] = 0;
		return (tab);
	}
	tab = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	tab = ft_split2(s, c, tab);
	return (tab);
}
