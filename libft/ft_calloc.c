#include "libft.h"
#include <stdlib.h>

void	*ftr_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*buf;

	buf = (char *)b;
	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	b = (void *)buf;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n;
	void	*buf;

	n = count * size;
	buf = malloc(n);
	if (buf)
		buf = ftr_memset(buf, 0, n);
	return (buf);
}
