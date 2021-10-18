#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	j;
	unsigned char	*str;

	j = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == j)
			return ((void *)&s[i]);
		i++;
	}
	if (str[i] == '\0' && j == '\0')
		return ((void *)&s[i]);
	return (NULL);
}
