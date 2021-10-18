#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mem;

	i = 0;
	while (s1[i] != '\0')
		i++;
	mem = (char *)malloc(sizeof(char) * i + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
