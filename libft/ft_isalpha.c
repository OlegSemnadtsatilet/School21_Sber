#include "libft.h"

int	ft_isalpha(int simb)
{
	if ((simb >= 'a' && simb <= 'z') || (simb >= 'A' && simb <= 'Z'))
		return (1);
	else
		return (0);
}
