#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destc;
	char	*srcc;

	destc = (char *)dest;
	srcc = (char *)src;
	if (dest == src || !n)
		return (dest);
	i = 0;
	while (i < n)
	{
		destc[i] = srcc[i];
		i++;
	}
	return ((void *)destc);
}
