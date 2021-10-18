#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		i;

	str = (char *)s;
	a = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && a == '\0')
		return (&str[i]);
	return (NULL);
}
