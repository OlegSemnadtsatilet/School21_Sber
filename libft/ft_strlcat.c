#include "libft.h"
#include <stdio.h>

size_t	str_lens(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const	char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;
	char	*src_char;

	src_char = (char *)src;
	d_len = str_lens(dst);
	s_len = str_lens(src_char);
	if (n <= d_len)
		return (s_len + n);
	i = d_len;
	j = 0;
	while (i < n - 1 && src_char[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
