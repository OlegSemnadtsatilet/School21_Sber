#include "libft.h"

int	ft_isdigit(int simb)
{
	if (simb >= '0' && simb <= '9')
		return (1);
	else
		return (0);
}
