#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*buf;
	size_t	i;

	buf = (char *)s;
	i = 0;
	while (i < n)
	{
		buf[i] = '\0';
		i++;
	}
	s = (void *)buf;
}
