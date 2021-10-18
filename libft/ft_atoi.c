#include "libft.h"

static int	strtonbr(const char *s)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			break ;
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return (number);
}	

int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || \
		str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		{
			i++;
			continue ;
		}
		if (str[i] == '-')
			return (strtonbr(&str[i + 1]) * -1);
		else if (str[i] == '+')
			return (strtonbr(&str[i + 1]));
		else
			return (strtonbr(&str[0]));
	}
	return (0);
}
