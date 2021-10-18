#include "libft.h"

int	ft_isascii(int simb)
{
	if (simb >= 0 && simb <= 127)
		return (1);
	else
		return (0);
}
