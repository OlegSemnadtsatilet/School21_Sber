#include "libft.h"

int	ft_isalnum(int simb)
{
	if ((simb >= 'a' && simb <= 'z') || (simb >= 'A' && simb <= 'Z') \
			|| (simb >= '0' && simb <= '9'))
		return (1);
	else
		return (0);
}
