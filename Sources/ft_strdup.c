#include "../Includes/pipex.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copy;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
