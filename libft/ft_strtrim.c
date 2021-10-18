#include "libft.h"
#include <stdlib.h>

int	char_in_set(char *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set) //blanks!!!
{
	int		start;
	int		end;
	char	*answer;
	int		pos;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen((char *)s1) - 1;
	start = 0;
	while (char_in_set((char *)set, s1[start]))
		start++;
	if (start == end)
		return (NULL);
	while (char_in_set((char *)set, s1[end]))
		end--;
	answer = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!answer)
		return (NULL);
	pos = -1;
	while (start + (++pos) <= end)
		answer[pos] = s1[start + pos];
	answer[pos] = '\0';
	return (answer);
}		
