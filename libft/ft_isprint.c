#include "libft.h"

int	ft_isprint(int simb)
{
	if (simb >= 32 && simb <= 126)
		return (1);
	else
		return (0);
}
