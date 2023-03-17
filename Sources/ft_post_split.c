#include "../Includes/pipex.h"

static void	**ft_post_split_bis(char **str, int start, int j)
{
//Faire un strjoin de toutes les cases entres les 2 single quotes puis  
}

char	**ft_post_split(char **str, int start)
{
	int	j;
	char	**res;

	if (!str[0])
		return (0);
	if (str[start])
	{
		while (str[start])
		{
			j = 0;
			while(str[start][j] != 39)
				j++;
			if (str[start][j] == 39)
				res = ft_post_split_bis(str, start, j);
			start++;
		}
	}
	return (res);
}
